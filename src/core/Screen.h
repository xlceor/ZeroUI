// Screen.h
#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include "Component.h"
#include <TFT_eSPI.h>

class Screen {
  private:
    std::vector<Component*> components;
    TFT_eSPI& tft;
    uint16_t bgColor;

  public:
    Screen(TFT_eSPI& tft, uint16_t backgroundColor);
    
    void addComponent(Component* comp);
    void draw();
    void setBgColor(uint16_t backgroundColor);
    void handleTouch(int x, int y);
};

#endif