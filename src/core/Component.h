#ifndef COMPONENT_H
#define COMPONENT_H

#include <TFT_eSPI.h>


class Component {
  public:
    virtual void Draw() = 0;
    virtual void CheckTouch(int x, int y) = 0;
};

#endif