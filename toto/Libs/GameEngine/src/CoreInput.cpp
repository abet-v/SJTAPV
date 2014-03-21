#include "CoreInput.hh"

CoreInput::CoreInput()
{
  memset(this->keyboardState_, 0, sizeof(this->keyboardState_));
  memset(this->mouseButtons_, 0, sizeof(this->mouseButtons_));
}

bool		CoreInput::getKeyState(int keyCode)
{
  return (this->keyboardState_[keyCode]);
}


bool		CoreInput::getMouseButtonState(int mouseButton)
{
  return (this->mouseButtons_[mouseButton]);
}

void		CoreInput::setKeyState(int keyCode, wchar_t c, bool state)
{
  InputEvent *event;

  this->keyboardState_[keyCode] = state;
  event = new InputEvent(keyCode, c);
  if(state)
    {
      dispatchEvent(event, InputEvent::EVENT_KEYDOWN);
    }
  else
    {
      dispatchEvent(event, InputEvent::EVENT_KEYUP);
    }
}

void		CoreInput::setMouseButtonState(int mouseButton, bool state)
{
  InputEvent *event;

  this->mouseButtons_[mouseButton] = state;
  event = new InputEvent(this->mousePosition_, mouseButton);
  if(state)
    {
      dispatchEvent(event, InputEvent::EVENT_MOUSEDOWN);
    }
  else
    {
      dispatchEvent(event, InputEvent::EVENT_MOUSEUP);
    }
}
