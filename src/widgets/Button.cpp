#include "Button.h"
#include <TFT_eSPI.h>

Button::Button(TFT_eSPI& tft_, int x, int y, int w, int h, uint16_t bgCol, uint16_t borCol, uint16_t txCol, const char* lbl) 
: tft(tft_)
{
    btn_x = x;
    btn_y = y;
    width = w;
    height = h;
    bgColor = bgCol;
    borderColor = borCol;
    textColor = txCol;
    label = lbl;
    event = nullptr;
}

void Button::setX(int new_x){
  btn_x = new_x;
}

void Button::setY(int new_y){
  btn_y = new_y;
}

void Button::setWidth(int w){
  width = w;
}

void Button::setHeight(int h){
  height = h;
}

void Button::setBgColor(uint16_t bgC){
  bgColor = bgC;
}

void Button::setBrColor(uint16_t brC){
  borderColor = brC;
}
 
void Button::setTxColor(uint16_t txC){
  textColor = txC;
}
void Button::setLabel(const char* lbl){
  label = lbl;
}

void Button::setEvent(void (*e)(int)){
  event = e;
}

void Button::CheckTouch(int tft_x, int tft_y) {

    if (tft_x > btn_x && tft_x< (btn_x + width) &&
        tft_y > btn_y && tft_y < (btn_y + height)) {
      if (event) event(1);
    }
}

void Button::Draw() {
    tft.fillRect(btn_x, btn_y, width, height, bgColor);
    tft.drawRect(btn_x, btn_y, width, height, borderColor);
    tft.setTextColor(textColor);
  if (label) {
    int16_t xOffset = (width - tft.textWidth(label)) / 2;
    int16_t yOffset = (height - tft.fontHeight()) / 2;
    tft.drawString(label, btn_x + xOffset, btn_y + yOffset);
  }
}
