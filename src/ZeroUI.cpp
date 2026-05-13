#include "ZeroUI.h"

namespace ZeroUI {
    static Screen* currentScreen = nullptr;
    static TFT_eSPI* display = nullptr;
    static XPT2046_Touchscreen* touch = nullptr;

    void begin(TFT_eSPI& tft, XPT2046_Touchscreen& ts) {
        display = &tft;
        touch = &ts;
    }

    void setScreen(Screen* scr) {
        currentScreen = scr;
        if (currentScreen) currentScreen->draw();
    }

    void loop() {
        if (!currentScreen || !touch) return;

        if (touch->touched()) {
            TS_Point p = touch->getPoint();
            int x = map(p.y, 300, 3600, 0, 320);
            int y = map(p.x, 400, 3700, 240, 0);
            currentScreen->handleTouch(x, y);
        }
    }
}
