#include "SceneManager.hh"


SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
  unsigned int	i;

  i = 0;
  while (i < this->scenes_.size())
    {
      delete this->scenes_[i];
      i++;
    }
  this->scenes_.clear();
}

void		SceneManager::addScene(Scene *scene)
{
  this->scenes_.push_back(scene);
}

void		SceneManager::removeScene(Scene *scene)
{
  unsigned int	i;

  i = 0;
  while (i < this->scenes_.size())
    {
      if (this->scenes_[i] == scene)
	{
	  this->scenes_.erase(this->scenes_.begin() + i);
	  return;
	}
      i++;
    }
}

void		SceneManager::Update()
{
  unsigned int	i;

  i = 0;
  while (i < this->scenes_.size())
    {
      if(this->scenes_[i]->isEnabled())
	{
	  this->scenes_[i]->Update();
	}
      i++;
    }
}

void		SceneManager::Render()
{
  unsigned int	i;

  i = 0;
  while (i < this->scenes_.size())
    {
      if(this->scenes_[i]->isEnabled())
	{
	  this->scenes_[i]->Render();
	}
      i++;
    }
}
