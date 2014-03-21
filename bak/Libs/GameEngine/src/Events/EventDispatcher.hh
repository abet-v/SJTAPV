#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

#include "EventHandler.hh"
#include <vector>

typedef struct {
  EventHandler *handler;
  int eventCode;
}EventEntry;

class			EventDispatcher : public EventHandler
{

public:
			EventDispatcher();
  virtual		~EventDispatcher();

  void			removeAllHandlers();
  void			removeAllHandlersForListener(EventHandler *handler);
  void			addEventListener(EventHandler *handler, int eventCode);
  void			removeEventListener(EventHandler *handler, int eventCode);
  void			__dispatchEvent(Event *event, int eventCode);
  virtual void		dispatchEvent(Event *event, int eventCode);
  virtual void		dispatchEventNoDelete(Event *event, int eventCode);

 protected:

  std::vector<EventEntry> handlerEntries;

};

#endif
