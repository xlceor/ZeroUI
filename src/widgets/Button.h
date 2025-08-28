#ifndef BUTTON_H
#define BUTTON_H


#include <TFT_eSPI.h>
#include "Component.h"

class Button : public Component {
  public:
    TFT_eSPI& tft;
    int btn_x, btn_y;
    int width;
    int height;
    uint16_t bgColor;
    uint16_t borderColor;
    uint16_t textColor;
    const char* label;
    void (*event)(int);


Button(TFT_eSPI& tft, int x, int y, int w, int h, uint16_t bgCol, uint16_t borCol, uint16_t txCol, const char* label);
    void setX(int x);
    void setY(int y);
    void setWidth(int w);
    void setHeight(int h);
    void setBgColor(uint16_t bgC);
    void setBrColor(uint16_t brC);
    void setTxColor(uint16_t txC);
    void setLabel(const char* lbl);
    void setEvent(void (*e)(int));
    void Draw() override;
    void CheckTouch(int tft_x, int tft_y) override;



};

#endif  // ARDUINO_H