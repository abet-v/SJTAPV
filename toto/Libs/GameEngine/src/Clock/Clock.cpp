#include "Clock.hh"

Clock::Clock()
{
  //this->firstTick_ = CoreServices::getCore()->getTicks();
  this->curTick_ = 0;
}

unsigned int		Clock::Update()
{
  //this->curTick_ = CoreServices::getCore()->getTicks() - this->firstTick_ - this->totalPaused_;
}

