#ifndef LABEL_H
#define LABEL_H


#include <TFT_eSPI.h>
#include "Component.h"


class Label : public Component {
public:
  TFT_eSPI& tft;
  uint16_t bgColor;
  uint16_t borderColor;
  uint16_t textColor;
  const char* label;
  int textSize; 

  Label(TFT_eSPI& tft, int x, int y, int w, int h,   // ✅ corregido
        uint16_t bgCol, uint16_t borCol, uint16_t txCol, const char* label);

  // setters
  void setBgColor(uint16_t bgC);
  void setBrColor(uint16_t brC);
  void setTxColor(uint16_t txC);
  void setLabel(const char* lbl);
  void setPosition(int newX, int newY) { x = newX; y = newY; }
  void setSize(int newW, int newH) { w = newW; h = newH; }
  void setTextSize(int size);

  // implementación de Component
  void draw() override;
  bool onEvent(const Event& e) override; 
};

#endif  // ARDUINO_H