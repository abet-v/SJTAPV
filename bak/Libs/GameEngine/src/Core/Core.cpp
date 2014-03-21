#include "Core.hh"

Core::Core(int xRes, int yRes, bool fullScreen)
{
  this->services_ = CoreServices::getInstance();
  this->services_->setCore(this);
  this->running_ = true;
  this->input_ = new CoreInput();
  this->xRes_ = xRes;
  this->yRes_ = yRes;
  this->fullScreen_ = fullScreen;
  this->refreshInterval_ = 1000 / 60;
}

Core::~Core()
{
}


CoreInput	*Core::getInput()
{
  return (this->input_);
}


void		Core::shutdown()
{
  this->running_ = false;
}


void		Core::doSleep()
{
  unsigned int ticks;
  unsigned int ticksSinceLastFrame;

  ticks = this->getTicks();
  ticksSinceLastFrame = ticks - lastSleepFrameTicks_;
  if (ticksSinceLastFrame <= refreshInterval_)
    {
      usleep((refreshInterval_ - ticksSinceLastFrame) * 1000);
    }
  lastSleepFrameTicks_ = this->getTicks();
}

void		Core::updateCore()
{
  this->frames_++;
  this->frameTicks_ = getTicks();
  this->elapsed_ = this->frameTicks_ - lastFrameTicks_;

  if (this->elapsed_ > 1000)
    this->elapsed_ = 1000;

  this->services_->Update(this->elapsed_);

  if (this->frameTicks_ - this->lastFPSTicks_ >= 1000)
    {
      this->fps_ = this->frames_;
      this->frames_ = 0;
      this->lastFPSTicks_ = this->frameTicks_;
    }
  this->lastFrameTicks_ = this->frameTicks_;
}

int		Core::getFps()
{
  return (this->fps_);
}

int		Core::getElapsed()
{
  return (this->elapsed_);
}


bool		Core::updateAndRender()
{
  bool		ret;

  ret = this->Update();
  this->Render();
  return (ret);
}
