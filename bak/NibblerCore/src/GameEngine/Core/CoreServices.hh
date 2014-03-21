#ifndef		CORESERVICES_HH
#define		CORESERVICES_HH

#include "GameEngine/SceneManager.hh"
#include "GameEngine/GameScreenManager.hh"
#include "GameEngine/RessourceManager.hh"


class			Renderer;
class			Core;
class			RessourceManager;
class			SoundManager;

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

  void			setSoundManager(SoundManager *soundManager);
  SoundManager		*getSoundManager();

  void			setRessourceManager(RessourceManager *ressourceManager);
  RessourceManager	*getRessourceManager();

  void			setRenderer(Renderer *renderer);
  Renderer		*getRenderer();

  ~CoreServices();

protected:
  CoreServices();

private:
  static CoreServices	*instance_;

  RessourceManager	*ressourceManager_;
  SceneManager		*sceneManager_;
  GameScreenManager	*gameScreenManager_;
  SoundManager		*soundManager_;

  Core			*core_;
  Renderer		*renderer_;

};

#include "Core.hh"
#include "GameEngine/RessourceManager.hh"
#include "GameEngine/Sound/SoundManager.hh"

#endif
