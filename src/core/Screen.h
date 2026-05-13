// Screen.h
#ifndef SCREEN_H
#define SCREEN_H

#include "Renderer.h"
#include <vector>
#include "Component.h"
#include <TFT_eSPI.h>

class Screen {
private:
    std::vector<Component*> components;
    TFT_eSPI& tft;
    uint16_t bgColor;
    Renderer renderer; 

public:
    Screen(TFT_eSPI& tft, uint16_t backgroundColor);
    virtual ~Screen();
    
    void addComponent(Component* comp);
    void draw();          
    void setBgColor(uint16_t backgroundColor);
    void handleTouch(int x, int y, EventType type);
    void handleEvent(const Event& e);
};

#endif