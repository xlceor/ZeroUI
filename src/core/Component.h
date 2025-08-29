#ifndef COMPONENT_H
#define COMPONENT_H

#include "Event.h"

class Component {
public:
  int x, y, w, h;
  bool visible = true;

  virtual void draw() = 0;
  virtual bool onEvent(const Event& e) = 0; // Devuelve true si consume el evento

  bool contains(int px, int py) {
    return (px >= x && px < x + w && py >= y && py < y + h);
  }
};

#endif