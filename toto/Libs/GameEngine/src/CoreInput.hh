#ifndef COREINPUT__
#define COREINPUT__

#include <stdio.h>
#include <string.h>

#include "Events/EventDispatcher.hh"
#include "Vector2.hh"
#include "Events/InputEvent.hh"

class CoreInput : public EventDispatcher
{
public:
  CoreInput();
  // ~CoreInput();

  bool		getMouseButtonState(int mouseButton);
  Vector2	getMousePosition();
  bool		getKeyState(int keyCode);

  void		setKeyState(int keyCode, wchar_t c, bool state);
  void		setMouseButtonState(int mouseButton, bool state);

private:
  bool		keyboardState_[512];
  bool		mouseButtons_[32];
  Vector2	mousePosition_;
};

#endif
