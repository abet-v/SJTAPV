
#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

class			Event;

class			EventHandler
{
 public:
			EventHandler();
  virtual		~EventHandler();

  virtual void		handleEvent(Event *event){ event = event;}

  void			*secondaryHandlerData;
};

#include "Event.hh"

#endif
