#include "CoreServices.hh"

CoreServices *CoreServices::instance_ = NULL;

CoreServices* CoreServices::getInstance()
{
  if (instance_)
    {
      return (instance_);
    }
  instance_ = new CoreServices;
  return (instance_);
}

CoreServices::CoreServices() : EventDispatcher()
{
  this->sceneManager_ = new SceneManager();
  this->gameScreenManager_ = new GameScreenManager();
  this->soundManager_ = new SoundManager();
  this->ressourceManager_ = new RessourceManager();
}

CoreServices::~CoreServices()
{

}

void		CoreServices::Update(int elapsed)
{
  this->sceneManager_->Update();
  this->gameScreenManager_->Update();
}

void		CoreServices::Render()
{
  this->sceneManager_->Render();
  this->gameScreenManager_->Render();
}

SceneManager	*CoreServices::getSceneManager()
{
  return (this->sceneManager_);
}

RessourceManager*CoreServices::getRessourceManager()
{
  return (this->ressourceManager_);
}

SoundManager	*CoreServices::getSoundManager()
{
  return (this->soundManager_);
}

GameScreenManager *CoreServices::getGameScreenManager()
{
  return (this->gameScreenManager_);
}

Core		*CoreServices::getCore()
{
  return (this->core_);
}

Renderer	*CoreServices::getRenderer()
{
  return (this->renderer_);
}

void		CoreServices::setSceneManager(SceneManager *sceneManager)
{
  this->sceneManager_ = sceneManager;
}

void		CoreServices::setGameScreenManager(GameScreenManager *screenManager)
{
  this->gameScreenManager_ = screenManager;
}

void		CoreServices::setSoundManager(SoundManager *soundManager)
{
  this->soundManager_ = soundManager;
}

void		CoreServices::setCore(Core *core)
{
  this->core_ = core;
}

void		CoreServices::setRenderer(Renderer *renderer)
{
  this->renderer_ = renderer;
}

void		CoreServices::setRessourceManager(RessourceManager *ressourceManager)
{
  this->ressourceManager_ = ressourceManager;
}
