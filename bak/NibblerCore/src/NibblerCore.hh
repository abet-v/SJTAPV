
#ifndef __NIBBLERCORE_H__
#define __NIBBLERCORE_H__

#include "GameEngine/Core/Core.hh"

#include "Bullet.hh"
#include "Player.hh"

#include <iostream>
#include <dlfcn.h>

class					NibblerCore : public EventHandler
{
public:
  NibblerCore();
  ~NibblerCore();

  bool					Update();
  void					handleEvent(Event *event);

private:
  bool					loadCore();


  void					shoot();

  Core					*core_;
  void					*dlHandle_;

  Scene					*scene_;
  Player				*player_;
};

#endif /* __NIBBLERCORE_H__ */
