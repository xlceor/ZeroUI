# ZeroUI — Microframework de interfaces embebidas

Un framework ligero y elegante para crear interfaces gráficas con botones, sliders, switches y pantallas múltiples, ideal para dispositivos como cyberdecks, relojes inteligentes o sistemas embebidos estilo Flipper Zero.

## 🚀 Características

- Modular y portable (ESP32 / STM32)
- Basado en TFT_eSPI + touch (XPT2046)
- Fácil de extender con nuevos widgets
- Estética unificada vía `style.h`

## 🧱 Componentes incluidos

- Botones (`Button`)
- Sliders (`Slider`)
- Switches (`ToggleSwitch`)
- Etiquetas (`Label`)
- Navegación entre pantallas

## 🧪 Requisitos

- [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI)
- [XPT2046_Touchscreen](https://github.com/PaulStoffregen/XPT2046_Touchscreen)

## 📂 Estructura típica
src/
    ZeroUI.h
    components/
        Button.h
        Slider.h

## 🧠 Ejemplo mínimo

```cpp
#include <ZeroUI.h>

ZeroUI.begin(tft);
ZeroUI.touch(x, y);
```
Creado por Carlos Osorio