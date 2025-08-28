# ZeroUI – Mini Framework para UIs táctiles en sistemas embebidos

ZeroUI es un **mini-framework ligero** para crear interfaces gráficas en sistemas embebidos (Arduino/ESP32, STM32, RP2040) usando pantallas TFT y touch (ej. XPT2046).  
El objetivo: simplificar el desarrollo de **UIs con múltiples pantallas, botones y eventos**, sin depender de librerías pesadas como LVGL.

Inspirado en la filosofía de “hazlo simple pero extensible”.  

---

## 🚀 Características actuales
- Sistema de **pantallas (Screen)** con cambio dinámico.  
- Soporte para **componentes** (heredados de una clase base común).  
- **Botones táctiles** con callback de evento.  
- Compatible con **TFT_eSPI** + **XPT2046_Touchscreen**.  
- Arquitectura lista para crecer con más widgets (Labels, Sliders, etc).  

---

## 🛸 Quick Start

### 1. Requisitos
- Librerías:  
  - [`TFT_eSPI`](https://github.com/Bodmer/TFT_eSPI)  
  - [`XPT2046_Touchscreen`](https://github.com/PaulStoffregen/XPT2046_Touchscreen)  
- Hardware probado: ESP32 + TFT ILI9341 + Touch XPT2046.

### 2. Crear una pantalla
```cpp
#include "Screen.h"

Screen* screen1 = new Screen(tft, TFT_BLACK);
```

### 3. Crear un botón
```cpp
#include "Button.h"

Button* btn = new Button(tft, 40, 60, 160, 40, TFT_RED, TFT_WHITE, TFT_WHITE, "Hola");
btn->setEvent([](int state){
  Serial.println("Botón presionado!");
});
screen1->addComponent(btn);
```
### 4. Dibujar la pantalla inicial
```cpp
currentScreen = screen1;
currentScreen->draw();
```
### 5. Manejar el touch en el loop
```cpp
if (ts.touched()) {
  TS_Point p = ts.getPoint();

  int x = map(p.y, 300, 3600, 0, 320);
  int y = map(p.x, 400, 3700, 240, 0);

  currentScreen->handleTouch(x, y);
}
```

## ⚙️ API Overview

### Clase Component (abstracta)
- void Draw() → dibuja el componente.
- void CheckTouch(int x, int y) → maneja interacción táctil.

### Clase Button : Component
- #### Constructor:

```cpp
Button(TFT_eSPI& tft, int x, int y, int w, int h,
       uint16_t bgCol, uint16_t borCol, uint16_t txCol,
       const char* label);
```

- #### Setters:
- setX(int), setY(int), setWidth(int), setHeight(int)
- setBgColor(uint16_t), setBrColor(uint16_t), setTxColor(uint16_t)
- setLabel(const char*)
- setEvent(void (*)(int)) → callback cuando se toca.

### Clase Screen
- Screen(TFT_eSPI& tft, uint16_t backgroundColor)
- void addComponent(Component* comp) → agrega un widget.
- void draw() → dibuja toda la pantalla.
- void handleTouch(int x, int y) → reenvía eventos táctiles a los componentes.

___
## 🧩 Ejemplo completo
```cpp
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>
#include "Screen.h"
#include "Button.h"

#define TOUCH_CS 7
SPIClass touchSPI(FSPI);
XPT2046_Touchscreen ts(TOUCH_CS);
TFT_eSPI tft = TFT_eSPI();

Screen* mainScreen;
Button* helloBtn;

void sayHello(int state) {
  Serial.println("¡Hola desde ZeroUI!");
}

void setup() {
  Serial.begin(115200);
  tft.init();
  tft.setRotation(3);

  touchSPI.begin(36, 37, 35); // CLK, MISO, MOSI
  ts.begin(touchSPI);
  ts.setRotation(3);

  mainScreen = new Screen(tft, TFT_BLACK);
  helloBtn = new Button(tft, 40, 60, 160, 40, TFT_RED, TFT_WHITE, TFT_WHITE, "Púlsame");
  helloBtn->setEvent(sayHello);
  mainScreen->addComponent(helloBtn);

  mainScreen->draw();
}

void loop() {
  if (ts.touched()) {
    TS_Point p = ts.getPoint();
    int x = map(p.y, 300, 3600, 0, 320);
    int y = map(p.x, 400, 3700, 240, 0);
    mainScreen->handleTouch(x, y);
  }
}
```
___
## 📂 Próximos pasos
- Añadir más widgets: Label, Slider, Checkbox, Image.
- Optimizar renderizado con “dirty rectangles”.
- Sistema de temas/estilos.
- Soporte para múltiples drivers de pantalla.

___
📜 Licencia

MIT License – úselo, modifíquelo, hágalo suyo.
t