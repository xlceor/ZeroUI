#include "VBox.h"

VBox::VBox(int x_, int y_, int w_, int h_, int spacing_)
  : spacing(spacing_), padding(0) {
  x = x_;
  y = y_;
  w = w_;
  h = h_;
}

void VBox::addChild(Component* child) {
  children.push_back(child);
  layout();
}

void VBox::setSpacing(int s) {
  spacing = s;
  layout();
}

void VBox::setPadding(int p) {
  padding = p;
  layout();
}

void VBox::layout() {
  int cy = y + padding;
  int innerX = x + padding;
  int innerW = w - 2 * padding;
  for (Component* c : children) {
    c->x = innerX;
    c->y = cy;
    c->w = innerW;
    cy += c->h + spacing;
  }
}

void VBox::draw(Renderer& r) {
  if (!visible) return;
  for (Component* c : children) {
    if (c->visible) c->draw(r);
  }
}

bool VBox::onEvent(const Event& e) {
  if (!visible) return false;
  for (auto it = children.rbegin(); it != children.rend(); ++it) {
    if ((*it)->onEvent(e)) return true;
  }
  return false;
}
