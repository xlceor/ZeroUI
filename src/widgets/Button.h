#ifndef BUTTON_H
#define BUTTON_H

#include <TFT_eSPI.h>
#include "../core/Component.h"
#include "../core/Event.h"
#include <functional>

class Button : public Component {
public:
  TFT_eSPI& tft;
  uint16_t bgColor;
  uint16_t borderColor;
  uint16_t textColor;
  const char* label;
  int textSize; 
  std::function<void(int)> event;

  Button(TFT_eSPI& tft, int x, int y, int w, int h,
         uint16_t bgCol, uint16_t borCol, uint16_t txCol, const char* label);

  // setters
  void setBgColor(uint16_t bgC);
  void setBrColor(uint16_t brC);
  void setTxColor(uint16_t txC);
  void setLabel(const char* lbl);
  void setEvent(std::function<void(int)> e);
  void setPosition(int newX, int newY) { x = newX; y = newY; }
  void setSize(int newW, int newH) { w = newW; h = newH; }
  void setTextSize(int size);


  // implementación de Component
  void draw(Renderer& r) override;
  bool onEvent(const Event& e) override;
};

#endif