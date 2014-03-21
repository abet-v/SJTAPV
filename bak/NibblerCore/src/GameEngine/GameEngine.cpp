
#include "GameEngine.hh"

GameState		*GameEngine::getCurrentState(void)
{
  // Get State manager and adk current state
  return (this->currentState_);
}

bool			GameEngine::isRunning(void)
{
  return (this->running_);
}

void			GameEngine::Tick(void)
{
  this->getCurrentState()->Update();
}

void			GameEngine::Render(void)
{
  this->getCurrentState()->Render();
}

void			GameEngine::HandleInput(void)
{
  this->getCurrentState()->HandleInput();
}

void			GameEngine::MainLoop(void)
{
  while (this->isRunning())
    {
      usleep(15000);
      this->HandleInput();
      this->Tick();
      this->Render();
    }
}

