#ifndef COMPONENT_H
#define COMPONENT_H

#include "Event.h"
#include "Renderer.h"

class Component {
public:
  virtual ~Component() {}
  int x, y, w, h;
  bool visible = true;

  virtual void draw(Renderer& r) = 0;
  virtual bool onEvent(const Event& e) = 0;

  bool contains(int px, int py) {
    return (px >= x && px < x + w && py >= y && py < y + h);
  }
};

#endif