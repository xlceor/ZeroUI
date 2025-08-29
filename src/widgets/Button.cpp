#include "Button.h"
#include <TFT_eSPI.h>

Button::Button(TFT_eSPI& tft_, int x_, int y_, int w_, int h_,
               uint16_t bgCol, uint16_t borCol, uint16_t txCol, const char* lbl) 
: tft(tft_), textSize(2)
{
    x = x_;
    y = y_;
    w = w_;
    h = h_;
    bgColor = bgCol;
    borderColor = borCol;
    textColor = txCol;
    label = lbl;
    event = nullptr;
}

void Button::setBgColor(uint16_t bgC){ bgColor = bgC; }
void Button::setBrColor(uint16_t brC){ borderColor = brC; }
void Button::setTxColor(uint16_t txC){ textColor = txC; }
void Button::setLabel(const char* lbl){ label = lbl; }
void Button::setTextSize(int size) { textSize = size; }


void Button::setEvent(void (*e)(int)){ event = e; }

bool Button::onEvent(const Event& e) {
    // Solo procesamos eventos que sean CLICK o TOUCH_DOWN
    if ((e.type == EventType::CLICK || e.type == EventType::TOUCH_DOWN) && contains(e.x, e.y)) {
        if (event) event(1);
        return true; // consume el evento
    }
    return false; // no consume otros eventos
}

void Button::draw() {
    tft.fillRect(x, y, w, h, bgColor);
    tft.drawRect(x, y, w, h, borderColor);
    tft.setTextColor(textColor);
    tft.setTextSize(textSize);   
    if (label) {
        int16_t xOffset = (w - tft.textWidth(label)) / 2;
        int16_t yOffset = (h - tft.fontHeight()) / 2;
        tft.drawString(label, x + xOffset, y + yOffset);
    }
}