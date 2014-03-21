#include "X11Renderer.hh"

X11Renderer::X11Renderer()
{
}

void	X11Renderer::Render()
{
}

void		X11Renderer::Initialize(X11Core *core)
{
  this->core_ = core;
}

void		X11Renderer::clearScreen(int color)
{
  this->core_->getMlxImage()->Clear(color);
}

void		X11Renderer::drawRect(Vector2 pos, int size, int color)
{
  int		x;
  int		y;

  x = 0;
  while (x < size)
    {
      y = 0;
      while (y < size)
	{
	  this->core_->getMlxImage()->PutPixel(pos.x + x, pos.y + y, color);
	  // this->core_->getMlxImage()->PutPixel(pos.x + (x * cos(45) - y * sin(45)), pos.y + (y * cos(45) + x * sin(45)), color);
	  y++;
	}
      x++;
    }
}


void		X11Renderer::drawImage(Image *image, Vector2 pos)
{
  this->core_->getMlxImage()->PutImage(image->getData(),
				       image->getWidth(),
				       image->getHeight(),
				       pos.x, pos.y, 0);
}
