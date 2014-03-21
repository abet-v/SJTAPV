#ifndef CORE_HH
#define CORE_HH

#include "CoreInput.hh"
#include "Renderer.hh"
#include "Events/EventDispatcher.hh"
#include "CoreServices.hh"

#include <unistd.h>

class			Core : public EventDispatcher
{
public:
  Core(int xRes, int yRes, bool fullScreen);
  ~Core();

  CoreInput		*getInput();

  virtual bool		Update() = 0;
  virtual unsigned int	getTicks() = 0;
  virtual void		Render() = 0;

  bool			updateAndRender();
  void			shutdown();
  void			doSleep();
  void			updateCore();

  int			getFps();
  int			getElapsed();
protected:
  int		xRes_;
  int		yRes_;
  bool		fullScreen_;

  bool		running_;

  unsigned int	totalTicks_;

  long		refreshInterval_;

  unsigned int	frameTicks_;
  unsigned int	lastFrameTicks_;
  unsigned int	lastFPSTicks_;
  unsigned int	elapsed_;

  unsigned int	lastSleepFrameTicks_;


  unsigned int	frames_;
  int		fps_;

  CoreServices	*services_;
  CoreInput	*input_;
  Renderer	*renderer_;


};

#endif
