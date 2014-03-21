#ifndef X11RENDERER_HH
#define X11RENDERER_HH

#include "Vector2.hh"
#include "Image.hh"
#include "Renderer.hh"


class			X11Core;

class			X11Renderer : public Renderer
{
public:
  X11Renderer();
  ~X11Renderer() {};

  void			Render();
  void			Initialize(X11Core *core);

  void			clearScreen(int color);
  void			drawRect(Vector2 pos, int size, int color);
  void			drawImage(Image *image, Vector2 pos);

private:
  X11Core		*core_;
};

#include "X11Core.hh"

#endif
