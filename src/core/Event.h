#ifndef EVENT_H
#define EVENT_H

enum class EventType {
  TOUCH_DOWN,
  TOUCH_UP,
  TOUCH_MOVE,
  CLICK
};

struct Event {
  EventType type;
  int x;
  int y;
};

#endif