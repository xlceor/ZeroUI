#ifndef ZEROUI_H
#define ZEROUI_H

// Dependencias 
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>

// Core
#include "core/Component.h"
#include "core/Screen.h"
#include "core/Renderer.h"

// Widgets
#include "widgets/Button.h"
#include "widgets/Label.h"
#include "widgets/VBox.h"

// Theming
#include "Theme.h"


namespace ZeroUI {
    struct TouchCalibration {
        uint16_t xMin, xMax;
        uint16_t yMin, yMax;
        bool swapXY;
        bool flipX, flipY;
    };

    void begin(TFT_eSPI& tft, XPT2046_Touchscreen& ts);
    void setCalibration(const TouchCalibration& cal);
    void setScreen(Screen* scr);
    void loop();
}

#endif