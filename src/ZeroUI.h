#ifndef ZEROUI_H
#define ZEROUI_H

// Dependencias externas necesarias
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>

// Core
#include "core/Component.h"
#include "core/Screen.h"
#include "core/Renderer.h"

// Widgets
#include "widgets/Button.h"
#include "widgets/Label.h"

// Espacio de nombres (opcional pero elegante)
namespace ZeroUI {
    void begin(TFT_eSPI& tft, XPT2046_Touchscreen& ts);
    void loop();
}

#endif // ZEROUI_H