#include "Label.h"
#include <TFT_eSPI.h>

Label::Label(TFT_eSPI& tft_, int x_, int y_, int w_, int h_,
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
}

void Label::setBgColor(uint16_t bgC){ bgColor = bgC; }
void Label::setBrColor(uint16_t brC){ borderColor = brC; }
void Label::setTxColor(uint16_t txC){ textColor = txC; }
void Label::setLabel(const char* lbl){ label = lbl; }
void Label::setTextSize(int size) { textSize = size; }


void Label::draw() {
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

bool Label::onEvent(const Event& e) {
    // Un Label no responde a eventos táctiles
    return false;
}