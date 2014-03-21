#ifndef _GAMESCREEN_HH
#define _GAMESCREEN_HH

#include "Events/EventDispatcher.hh"
#include "Core/CoreServices.hh"
#include "GameScreenManager.hh"
#include "Entities/BaseEntity.hh"

class GameScreen : public BaseEntity
{
public:
  GameScreen();

  void			Render();
  void			Update();

  bool			isEnabled();


private:
  bool			enabled_;
};

#endif
