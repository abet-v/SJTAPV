#include "GameScreenManager.hh"

GameScreenManager::GameScreenManager()
{
}

GameScreenManager::~GameScreenManager()
{
  unsigned int		i;

  i = 0;
  while (i < this->screens_.size())
    {
      delete this->screens_[i];
      i++;
    }
  this->screens_.clear();
}

void		GameScreenManager::addGameScreen(GameScreen *screen)
{
  this->screens_.push_back(screen);
}

void		GameScreenManager::removeGameScreen(GameScreen *screen)
{
  unsigned int	i;

  i = 0;
  while (i < this->screens_.size())
    {
      if (this->screens_[i] == screen)
	{
	  this->screens_.erase(this->screens_.begin() + i);
	  return;
	}
      i++;
    }
}

void		GameScreenManager::Update()
{
  unsigned int	i;

  i = 0;
  while (i < this->screens_.size())
    {
      if(this->screens_[i]->isEnabled())
	{
	  this->screens_[i]->Update();
	}
      i++;
    }
}

void		GameScreenManager::Render()
{
  unsigned int	i;

  i = 0;

  while (i < this->screens_.size())
    {
      if(this->screens_[i]->isEnabled())
	{
	  this->screens_[i]->Render();
	}
      i++;
    }
}
