#include "GameScreen.hh"

GameScreen::GameScreen()
{
  this->enabled_ = true;
  CoreServices::getInstance()->getGameScreenManager()->addGameScreen(this);
}

void		GameScreen::Render()
{
  this->renderChildrens();
}

void		GameScreen::Update()
{
  //  this->doUpdates();
}

bool		GameScreen::isEnabled()
{
  return (this->enabled_);
}
