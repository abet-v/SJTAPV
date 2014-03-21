#ifndef		CORESERVICES_HH
#define		CORESERVICES_HH

#include "SceneManager.hh"
#include "GameScreenManager.hh"

class			Renderer;
class			Core;

class			CoreServices : public EventDispatcher
{
 public:

  static CoreServices	*getInstance();

  void			Update(int elapsed);
  void			Render();

  void			setCore(Core *core);
  Core			*getCore();

  void			setSceneManager(SceneManager *sceneManager);
  SceneManager		*getSceneManager();

  void			setGameScreenManager(GameScreenManager *screenManager);
  GameScreenManager	*getGameScreenManager();

  void			setRenderer(Renderer *renderer);
  Renderer		*getRenderer();

  ~CoreServices();

protected:
  CoreServices();

private:
  static CoreServices	*instance_;

  SceneManager		*sceneManager_;
  GameScreenManager	*gameScreenManager_;

  Core			*core_;
  Renderer		*renderer_;

};

#include "Core.hh"

#endif
