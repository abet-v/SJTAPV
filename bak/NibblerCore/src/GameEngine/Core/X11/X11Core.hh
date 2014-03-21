#ifndef X11CORE_HH
#define X11CORE_HH

#include "Core/Core.hh"
#include "MLXLib/MLXWindow.hh"
#include "MLXLib/MLXImage.hh"
#include <sys/time.h>
#include "X11Renderer.hh"

// #include <X11/XKBlib.h>
// #include <X11/keysym.h>
// #include <X11/Xlib.h>
// #include <X11/Xutil.h>
// #include <X11/Xos.h>

class			X11Core : public Core
{
public:
  X11Core(int xRes, int yRes, bool fullScreen);

  bool			Update();
  void			Render();

  unsigned int		getTicks();

  MLXImage*		getMlxImage();
private:
  t_xvar*			xvar_;
  MLXWindow*			window_;
  MLXImage*			image_;

  void	dealEvents();
};

#endif
