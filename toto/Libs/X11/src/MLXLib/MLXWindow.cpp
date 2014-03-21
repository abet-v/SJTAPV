
#include "MLXWindow.hh"

MLXWindow::MLXWindow(t_xvar *xvar, const int width, const int height, const std::string &name)
{

  this->_win = static_cast<t_win_list*>(mlx_new_window(xvar, width, height, const_cast<char *>(name.c_str())));
  if (!this->_win)
    {
      //  throw MyException("Fail to create window");
    }
  this->_xvar = xvar;
  this->_width = width;
  this->_height = height;

}

MLXWindow::MLXWindow(t_xvar *xvar, const int width, const int height)
{
  this->_win = static_cast<t_win_list*>(mlx_new_window(xvar, width, height, NULL));
  if (!this->_win)
    {
      //  throw MyException("Fail to create window");
    }
  this->_xvar = xvar;
  this->_width = width;
  this->_height = height;
}

MLXWindow::~MLXWindow()
{
  mlx_destroy_window(this->_xvar, this->_win);
}

void		MLXWindow::PutImage(const MLXImage *image, const int x, const int y)
{
  // GC		gc;
  // t_img		*img;

  // img = image->Image();
  // gc = this->_win->gc;
  // if (img->gc)
  //   {
  //     gc = img->gc;
  //     XSetClipOrigin(this->_xvar->display, gc, x, y);
  //   }
  // if (img->type == MLX_TYPE_SHM)
  //   XShmPutImage(this->_xvar->display, img->pix, this->_win->gc, img->image, 0, 0, 0, 0,
  // 		 img->width, img->height, False);
  // if (img->type == MLX_TYPE_XIMAGE)
  //   XPutImage(this->_xvar->display, img->pix, this->_win->gc, img->image, 0, 0, 0, 0,
  // 	      img->width, img->height);
  // XCopyArea(this->_xvar->display, img->pix, this->_win->window, gc,
  // 	    0, 0, img->width, img->height, x, y);
  // if (this->_xvar->do_flush)
  //   XFlush(this->_xvar->display);
  mlx_put_image_to_window(this->_xvar, this->_win, image->Image(), x, y);
}

void		MLXWindow::PutImage(const MLXImage *image)
{
  this->PutImage(image, 0, 0);
}

void		MLXWindow::MoveWindow(const int x, const int y)
{
  XMoveWindow(this->_xvar->display, this->_win->window, x, y);
}

void		MLXWindow::ExitHook()
{
  Atom			wmDeleteMessage;

  wmDeleteMessage = XInternAtom(this->_xvar->display, "WM_DELETE_WINDOW", False);
  XSetWMProtocols(this->_xvar->display, this->_win->window, &wmDeleteMessage, 1);
}

void		MLXWindow::NewHook(const int x_event, const int x_mask)
{
  this->_win->hooks[x_event].hook = (int (*)())1;
  this->_win->hooks[x_event].param = NULL;
  this->_win->hooks[x_event].mask = x_mask;
}

void		MLXWindow::ApplyHook()
{
  int			i;
  XSetWindowAttributes	xwa;

  xwa.event_mask = 0;
  i = MLX_MAX_EVENT;
  while (i--)
    xwa.event_mask |= this->_win->hooks[i].mask;
  XChangeWindowAttributes(this->_xvar->display, this->_win->window, CWEventMask, &xwa);
}

std::list<XEvent>	MLXWindow::GetEvents()
{
  XEvent		event;
  XWindowAttributes	attr_embed;

  XGetWindowAttributes(this->_xvar->display, this->_win->window, &attr_embed);

  this->_events.clear();
  //  while (XPending(this->_xvar->display))
  while (XCheckWindowEvent(this->_xvar->display,
			   this->_win->window,
			   attr_embed.your_event_mask,
			   &event))
    {
      this->_events.push_back(event);
      // XNextEvent(this->_xvar->display, &event);
      // if (this->_win->window == event.xany.window)
      // 	if (event.type < MLX_MAX_EVENT)
      // 	  if (this->_win->hooks[event.type].hook)
      // 	    this->_events.push_back(event);
    }
  return (this->_events);
}

int		MLXWindow::Height() const
{
  return (this->_height);
}

int		MLXWindow::Width() const
{
  return (this->_width);
}

t_win_list	*MLXWindow::Win()
{
  return (this->_win);
}
