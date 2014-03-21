#include "X11Core.hh"

X11Core::X11Core(int xRes, int yRes, bool fullScreen) : Core(xRes, yRes, fullScreen)
{
  this->renderer_ = new X11Renderer();
  ((X11Renderer*)this->renderer_)->Initialize(this);
  this->services_->setRenderer(this->renderer_);

  std::cout << "X11Core : initialized." << std::endl;
  this->xvar_ = static_cast<t_xvar*>(mlx_init());

  this->image_ = new MLXImage(this->xvar_, this->xRes_, this->yRes_);
  this->window_ = new MLXWindow(this->xvar_, this->xRes_, this->yRes_);
  this->window_->NewHook(KeyPress, KeyPressMask);
  this->window_->NewHook(KeyRelease, KeyReleaseMask);
  this->window_->NewHook(Expose, ExposureMask);
  this->window_->ApplyHook();
}

void	X11Core::Render()
{
  this->services_->Render();
  this->window_->PutImage(this->image_);
  XSync(this->xvar_->display, false);
}

bool	X11Core::Update()
{
  if(!this->running_)
    return (false);

  doSleep();
  updateCore();

  this->dealEvents();
  return (true);
}

void	X11Core::dealEvents()
{
  std::list<XEvent>             list;
  std::list<XEvent>::iterator   it;
  wchar_t			c;

  list = this->window_->GetEvents();
  for (it = list.begin() ; it != list.end() ; ++it)
    {
      switch ((*it).type)
	{
	case Expose:
	  if ((*it).xexpose.count == 0)
	    {
	      std::cout << (int)(*it).xexpose.count << std::endl;
	      this->window_->PutImage(this->image_);
	    }
	  else
	    std::cout << "    LAAAAL" << std::endl;
	  break;
	case KeyPress:
	  XLookupString(&(*it).xkey, (char*)&c, 1, NULL, NULL);
	  this->input_->setKeyState((*it).xkey.keycode, c, true);
	    break;
	case KeyRelease:
	  XLookupString(&(*it).xkey, (char*)&c, 1, NULL, NULL);
	  this->input_->setKeyState((*it).xkey.keycode, c, false);
	    break;
	default:
	  break;
	}
    }
}

unsigned int X11Core::getTicks()
{
  static int		firstTicks;
  int			curTicks;
  struct timeval	tvp;

  gettimeofday(&tvp, NULL);
  curTicks = tvp.tv_sec * 1000 + tvp.tv_usec / 1000;
   if (firstTicks == 0)
     {
       firstTicks = curTicks;
     }
   this->totalTicks_ = curTicks - firstTicks;
   return (this->totalTicks_);
}

MLXImage	*X11Core::getMlxImage()
{
  return (this->image_);
}
