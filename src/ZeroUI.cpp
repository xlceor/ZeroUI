#include "ZeroUI.h"

namespace ZeroUI {
    static Screen* currentScreen = nullptr;
    static TFT_eSPI* display = nullptr;
    static XPT2046_Touchscreen* touch = nullptr;

    static TouchCalibration calibration = {300, 3600, 400, 3700, true, false, true};
    static bool wasTouched = false;
    static bool wasLongPressed = false;
    static uint32_t touchStartTime = 0;
    static int lastX = -1;
    static int lastY = -1;

    void begin(TFT_eSPI& tft, XPT2046_Touchscreen& ts) {
        display = &tft;
        touch = &ts;
    }

    void setCalibration(const TouchCalibration& cal) {
        calibration = cal;
    }

    void setScreen(Screen* scr) {
        currentScreen = scr;
        if (currentScreen) currentScreen->draw();
    }

    void loop() {
        if (!currentScreen || !touch) return;

        bool isTouched = touch->touched();
        
        if (isTouched) {
            TS_Point p = touch->getPoint();
            
            int rawX = calibration.swapXY ? p.y : p.x;
            int rawY = calibration.swapXY ? p.x : p.y;

            int x = map(rawX, calibration.xMin, calibration.xMax, 0, display->width());
            int y = map(rawY, calibration.yMin, calibration.yMax, 0, display->height());

            if (calibration.flipX) x = display->width() - x;
            if (calibration.flipY) y = display->height() - y;

            if (!wasTouched) {
                // TOUCH_DOWN
                currentScreen->handleTouch(x, y, EventType::TOUCH_DOWN);
                touchStartTime = millis();
                wasLongPressed = false;
            } else {
                if (millis() - touchStartTime >= 500 && !wasLongPressed) {
                    currentScreen->handleTouch(x, y, EventType::LONG_PRESS);
                    wasLongPressed = true;
                }
                
                if (x != lastX || y != lastY) {
                    // TOUCH_MOVE
                    currentScreen->handleTouch(x, y, EventType::TOUCH_MOVE);
                }
            }
            
            lastX = x;
            lastY = y;
            wasTouched = true;
        } else {
            if (wasTouched) {
                // TOUCH_UP
                currentScreen->handleTouch(lastX, lastY, EventType::TOUCH_UP);
                
                // Check for CLICK (only if not a long press)
                if (!wasLongPressed && millis() - touchStartTime < 500) {
                    currentScreen->handleTouch(lastX, lastY, EventType::CLICK);
                }
            }
            wasTouched = false;
            wasLongPressed = false;
        }
    }
}
