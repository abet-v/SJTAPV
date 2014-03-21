#include "InputEvent.hh"

InputEvent::InputEvent(Vector2 mousePosition, int mouseButton)
{
  this->mouseButton = mouseButton;
  this->mousePosition = mousePosition;
}

InputEvent::InputEvent(int keycode, wchar_t c)
{
  this->keycode = keycode;
  this->keyAscii = c;
}

Vector2		InputEvent::getMousePosition()
{
  return (this->mousePosition);
}

int		InputEvent::getKey()
{
  return (this->keycode);
}

int		InputEvent::getKeyAscii()
{
  return (this->keyAscii);
}

int		InputEvent::getMouseButton()
{
  return (this->mouseButton);
}
