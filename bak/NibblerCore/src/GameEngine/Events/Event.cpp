#include "Event.hh"

Event::Event() {
  this->deleteOnDispatch = true;
}

Event::Event(int eventCode) {
  setEventCode(eventCode);
}

Event::~Event() {

}

const std::string&		Event::getEventType() const
{
  return (this->eventType_);
}

int			Event::getEventCode() const
{
  return (this->eventCode_);
}

EventDispatcher		*Event::getDispatcher() const
{
  return (this->dispatcher_);
}

void			Event::setDispatcher(EventDispatcher *dispatcher)
{
  this->dispatcher_ = dispatcher;
}

void			Event::setEventCode(int eventCode)
{
  this->eventCode_ = eventCode;
}
