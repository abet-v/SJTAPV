#include "Scene.hh"

Scene::Scene()
{
  this->enabled_ = true;
  CoreServices::getInstance()->getSceneManager()->addScene(this);
}

void		Scene::Render()
{
  
}

void		Scene::Update()
{
}

bool		Scene::isEnabled()
{
  return (this->enabled_);
}
