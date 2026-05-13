#include "Label.h"
#include "../core/Renderer.h"

Label::Label(TFT_eSPI& tft_, int x_, int y_, int w_, int h_,
             uint16_t bgCol, uint16_t borCol, uint16_t txCol, const char* lbl)
: tft(tft_), textSize(2) {
    x = x_;
    y = y_;
    w = w_;
    h = h_;
    bgColor = bgCol;
    borderColor = borCol;
    textColor = txCol;
    label = lbl;
}

void Label::setBgColor(uint16_t bgC) { bgColor = bgC; }
void Label::setBrColor(uint16_t brC) { borderColor = brC; }
void Label::setTxColor(uint16_t txC) { textColor = txC; }
void Label::setLabel(const std::string& lbl) { 
    label = lbl; 
}
void Label::setTextSize(int size) { textSize = size; }

bool Label::onEvent(const Event& e) {
    return false;
}

void Label::draw(Renderer& r) {
    r.fillRect(x, y, w, h, bgColor);
    r.drawRect(x, y, w, h, borderColor);
    if (!label.empty()) {
        tft.setTextColor(textColor);
        tft.setTextSize(textSize);
        tft.setTextDatum(MC_DATUM);
        tft.drawString(label.c_str(), x + w/2, y + h/2);
    }
}