#ifndef EVENT_H
#define EVENT_H

#include <string>

class			EventDispatcher;

class			Event
{
public:
 Event();

 Event(int eventCode);
 virtual		~Event();

 int			getEventCode() const;
 EventDispatcher	*getDispatcher() const;

 void			setEventCode(int eventCode);
 void			setDispatcher(EventDispatcher *dispatcher);
 const			std::string& getEventType() const;

 bool			deleteOnDispatch;

protected:

  std::string		eventType_;
  EventDispatcher	*dispatcher_;
  int			eventCode_;

};

#include "EventDispatcher.hh"

#endif
