#include "EventDispatcher.hh"

EventDispatcher::EventDispatcher() : EventHandler()
{
  
}

EventDispatcher::~EventDispatcher()
{

}

void			EventDispatcher::addEventListener(EventHandler *handler, int eventCode)
{
  EventEntry		newEntry;

  newEntry.handler = handler;
  newEntry.eventCode = eventCode;
  this->handlerEntries.push_back(newEntry);
}

void			EventDispatcher::removeAllHandlers()
{
  this->handlerEntries.clear();
}

void			EventDispatcher::removeAllHandlersForListener(EventHandler *handler)
{
  std::vector<EventEntry>::iterator it;

  it = this->handlerEntries.begin();
  while (it != this->handlerEntries.end())
  {
    if ((*it).handler == handler)
     it = this->handlerEntries.erase(it);
   else
     ++it;
 }

}

void			EventDispatcher::removeEventListener(EventHandler *handler, int eventCode)
{
  unsigned int		i;

  i = 0;
  while (i < this->handlerEntries.size())
  {
    if (this->handlerEntries[i].eventCode == eventCode
     && this->handlerEntries[i].handler == handler)
     this->handlerEntries.erase(this->handlerEntries.begin() + i);
   ++i;
 }
}

void			EventDispatcher::__dispatchEvent(Event *event, int eventCode)
{
  unsigned int		i;

  //                event->setDispatcher(dynamic_cast<void*>(this));
  event->setDispatcher(this);
  event->setEventCode(eventCode);
  i = 0;
  while (i < this->handlerEntries.size())
  {
    if (this->handlerEntries[i].eventCode == eventCode)
    {
	  //                                if(handlerEntries[i].handler->onEvent != NULL) {
	  //                                        handlerEntries[i].handler->onEvent(event);
	  //                                }
     handlerEntries[i].handler->handleEvent(event);
	  //handlerEntries[i].handler->secondaryHandler(event);
   }
   ++i;
 }
}

void			EventDispatcher::dispatchEventNoDelete(Event *event, int eventCode)
{
  this->__dispatchEvent(event,eventCode);
}

void			EventDispatcher::dispatchEvent(Event *event, int eventCode)
{
  this->__dispatchEvent(event,eventCode);
  delete event;
}
