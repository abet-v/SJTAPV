#include "X11Renderer.hh"

X11Renderer::X11Renderer()
{
}

// X11Renderer::~X11Renderer()
// {
// }

void	X11Renderer::Render()
{

}

void		X11Renderer::Initialize(X11Core *core)
{
  this->core_ = core;
}

void		X11Renderer::drawRect(Vector2 pos, int size, int color)
{
  MLXImage	*image;
  int		x;
  int		y;

  x = 0;
  image = this->core_->getMlxImage();
  image->Clear(0xFF0098);
  while (x < size)
    {
      y = 0;
      while (y < size)
	{
	  image->PutPixel(pos.x + x, pos.y + y, color);
	  y++;
	}
      x++;
    }
}


