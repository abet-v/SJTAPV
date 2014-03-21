#include "Scene.hh"

Scene::Scene()
{
  this->enabled_ = true;
  CoreServices::getInstance()->getSceneManager()->addScene(this);
}

void		Scene::Render()
{
  Renderer *renderer;

  renderer = CoreServices::getInstance()->getRenderer();
  renderer->clearScreen(0x0);
  this->renderChildrens();
}

void		Scene::Update()
{
}

bool		Scene::isEnabled()
{
  return (this->enabled_);
}
