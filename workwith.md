# Working with ZeroUI: Deep Dive & Guide

ZeroUI is a lightweight, component-based UI framework for Arduino-compatible microcontrollers (specifically optimized for ESP32 and TFT displays using `TFT_eSPI`). This guide provides an in-depth look at its architecture and how to effectively build interfaces with it.

---

## 1. Architectural Overview

ZeroUI follows a hierarchical, event-driven architecture designed for low-memory environments.

### Core Pillars:
1.  **Component-Based:** Everything is a `Component`. Components are self-contained units that handle their own drawing and event logic.
2.  **The Renderer Abstraction:** Drawing is abstracted through the `Renderer` class. This allows components to remain decoupled from the specific graphics library implementation (currently wrapping `TFT_eSPI`).
3.  **Event Propagation:** Events (like touch) are propagated from the `Screen` down to components. ZeroUI uses a "reverse-order" traversal for events, meaning the components added last (on top) receive events first.
4.  **Layouts (Containers):** Containers like `VBox` are components that manage the position and size of their children, enabling dynamic layouts.

---

## 2. Core Concepts

### `ZeroUI` Namespace
The entry point of the framework. It manages the global state:
- `begin(tft, ts)`: Initializes the framework with display and touch references.
- `setScreen(Screen*)`: Switches the active screen.
- `loop()`: Must be called in the main `loop()`. It handles touch input and dispatches it to the current screen.

### `Screen`
A `Screen` is a container for all components in a particular view. 
- It owns the background color.
- It manages the list of components.
- It orchestrates the `draw()` and `handleEvent()` cycles.

### `Component` (Abstract Base Class)
All UI elements inherit from this.
- `draw(Renderer& r)`: Pure virtual. Where the component renders itself.
- `onEvent(const Event& e)`: Pure virtual. Where the component reacts to touch/clicks. Returns `true` if the event was consumed.
- `contains(x, y)`: Helper to check if a coordinate is within the component's bounds.

---

## 3. Creating a Custom UI

### Basic Setup Example
```cpp
#include <ZeroUI.h>

TFT_eSPI tft = TFT_eSPI();
XPT2046_Touchscreen ts(7); 

Screen* mainScreen;

void setup() {
  tft.init();
  ZeroUI::begin(tft, ts);

  mainScreen = new Screen(tft, TFT_BLACK);
  
  Button* btn = new Button(tft, 10, 10, 100, 40, TFT_BLUE, TFT_WHITE, TFT_WHITE, "Click Me");
  btn->setEvent([](int state) {
    Serial.println("Button Pressed!");
  });

  mainScreen->addComponent(btn);
  ZeroUI::setScreen(mainScreen);
}

void loop() {
  ZeroUI::loop();
}
```

---

## 4. Layouts: Using VBox
`VBox` (Vertical Box) automatically stacks components vertically.

```cpp
VBox* layout = new VBox(20, 20, 200, 200, 10); // x, y, w, h, spacing
layout->addChild(new Label(tft, 0, 0, 150, 30, TFT_BLACK, TFT_BLACK, TFT_WHITE, "Settings"));
layout->addChild(new Button(tft, 0, 0, 150, 40, TFT_RED, TFT_WHITE, TFT_WHITE, "Reset"));

mainScreen->addComponent(layout);
```
*Note: When using VBox, the internal `layout()` method recalculates the `y` positions of children based on their order and the specified spacing.*

---

## 5. Theming
ZeroUI supports a `Theme` structure to maintain visual consistency.

```cpp
struct Theme {
  uint16_t background;
  uint16_t primary;
  uint16_t secondary;
  uint16_t accent;
  uint16_t text;
  uint16_t border;
  uint8_t  textSize;
};
```
You can define custom themes or use built-in ones like `RetroTerminal`.

---

## 6. Tips for Advanced Usage

### Efficient Redrawing
Currently, `ZeroUI` performs a full redraw when `setScreen` is called. For dynamic updates:
- Components can call their own `draw(renderer)` if their state changes.
- **Tip:** If a component changes visually (e.g., a button press), only redraw that component to avoid flickering.

### Custom Components
To create your own widget, inherit from `Component`:
```cpp
class MyWidget : public Component {
public:
    void draw(Renderer& r) override {
        if (!visible) return;
        r.fillRect(x, y, w, h, TFT_GREEN);
    }
    bool onEvent(const Event& e) override {
        if (contains(e.x, e.y)) {
            // Handle event...
            return true; // Event consumed
        }
        return false;
    }
};
```

### Event Handling Order
Events are handled in **reverse order** of addition. If two components overlap, the one added *last* will receive the touch event first. This is crucial for modals or overlays.

### Performance
- Use `Renderer` methods instead of direct `TFT_eSPI` calls within components to ensure future-proofing.
- Keep `loop()` fast; avoid heavy logic inside `onEvent` callbacks. Use state flags and handle logic in the main `loop()` if necessary.

---

## 7. Component Reference

| Component | Purpose | Key Methods |
| :--- | :--- | :--- |
| `Label` | Static text display. | `setTextSize()`, `setLabel()` |
| `Button` | Interactive trigger. | `setEvent()`, `setBgColor()` |
| `VBox` | Vertical container. | `addChild()`, `setSpacing()` |
| `Screen` | Top-level container. | `addComponent()`, `setBgColor()` |
