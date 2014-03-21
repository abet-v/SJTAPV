
#ifndef __GAMEENGINE_H__
#define __GAMEENGINE_H__

#include "GameState.hh"
#include <vector>
#include <unistd.h>
#include <iostream>

class					GameEngine
{

protected:
  void					Render(void);
  void					Tick(void);
  void					HandleInput(void);
  GameState				*getCurrentState(void);

  GameState				*currentState_;
  std::vector<GameState*>		states_;
  bool					running_;

public:
  bool					isRunning(void);
  void					MainLoop(void);
};

#endif /* __GAMEENGINE_H__ */
