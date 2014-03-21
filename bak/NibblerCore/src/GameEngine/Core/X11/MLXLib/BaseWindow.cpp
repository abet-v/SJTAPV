
#include "BaseWindow.hh"

unsigned int		BaseWindow::GetWidth() const
{
  return (this->width_);
}

unsigned int		BaseWindow::GetHeight() const
{
  return (this->height_);
}

Window			BaseWindow::GetWindow()
{
  return (this->window_);
}

Display			*BaseWindow::GetDisplay()
{
  return (this->display_);
}

bool			BaseWindow::Create(Display *display,
					   Window parent,
					   int x, int y,
					   unsigned int width, unsigned int height,
					   unsigned int border_width,
					   int depth,
					   unsigned int type_class,
					   Visual *Visual,
					   unsigned long valuemask,
					   XSetWindowAttributes *attributes)
{
  this->window_ = XCreateWindow(display, parent,
				x, y,
				width, height,
				border_width,
				depth,
				type_class,
				Visual,
				valuemask,
				attributes);
  this->width_ = width;
  this->height_ = height;
  return (this->window_ ? true : false);
}


