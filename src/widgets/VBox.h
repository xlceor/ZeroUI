#ifndef VBOX_H
#define VBOX_H

#include <vector>
#include "../core/Component.h"

class VBox : public Component {
public:
  VBox(int x, int y, int w, int h, int spacing = 4);

  void addChild(Component* child);
  void setSpacing(int s);
  void setPadding(int p);

  void draw(Renderer& r) override;
  bool onEvent(const Event& e) override;

private:
  std::vector<Component*> children;
  int spacing;
  int padding;

  void layout();
};

#endif
