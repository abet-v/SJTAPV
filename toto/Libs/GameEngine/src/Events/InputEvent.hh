#ifndef INPUTEVENT_H
#define INPUTEVENT_H

#include "Vector2.hh"
#include "Event.hh"
#include <string>

class InputEvent : public Event
{
 public:
  InputEvent(Vector2 mousePosition, int mouseButton);
  InputEvent(int keycode, wchar_t c);

  //virtual ~InputEvent();

  static const int EVENTBASE_INPUTEVENT = 0x400;

  static const int EVENT_MOUSEDOWN = EVENTBASE_INPUTEVENT + 0;
  static const int EVENT_MOUSEUP = EVENTBASE_INPUTEVENT + 1;

  static const int EVENT_MOUSEMOVE = EVENTBASE_INPUTEVENT + 2;

  static const int EVENT_KEYDOWN = EVENTBASE_INPUTEVENT + 3;
  static const int EVENT_KEYUP = EVENTBASE_INPUTEVENT + 4;

  Vector2	getMousePosition();
  int		getKey();
  int		getKeyAscii();
  int		getMouseButton();


  wchar_t	keyAscii;
  int		mouseButton;
  int		keycode;
  Vector2	mousePosition;

};

#endif
