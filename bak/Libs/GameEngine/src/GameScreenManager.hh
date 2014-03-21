#ifndef GAMESCREENMANAGER__H
#define GAMESCREENMANAGER__H

#include <vector>

class			GameScreen;

class			GameScreenManager
{
public:
  GameScreenManager();
  ~GameScreenManager();

  void			Update();
  void			Render();

  void			addGameScreen(GameScreen *screen);
  void			removeGameScreen(GameScreen *screen);
private:
  std::vector<GameScreen*>	screens_;
};

#include "GameScreen.hh"


#endif
