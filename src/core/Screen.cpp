// Screen.cpp
#include "Screen.h"
#include <TFT_eSPI.h>

Screen::Screen(TFT_eSPI &main_tft, uint16_t backgroundColor)
    : tft(main_tft), bgColor(backgroundColor), renderer(main_tft) {}
void Screen::addComponent(Component *comp)
{
  components.push_back(comp);
}

void Screen::draw() {
    renderer.fillRect(0, 0, tft.width(), tft.height(), bgColor);
    for (Component* comp : components) {
        comp->draw(renderer); 
    }
}
void Screen::handleTouch(int x, int y)
{
  Event e;
  e.type = EventType::TOUCH_DOWN;
  e.x = x;
  e.y = y;
  handleEvent(e);
}

void Screen::handleEvent(const Event &e)
{
  for (auto it = components.rbegin(); it != components.rend(); ++it)
  {
    if ((*it)->onEvent(e))
    {
      break; 
    }
  }
}