#ifndef RENDERER_HH
#define RENDERER_HH

#include "Vector2.hh"

class			Renderer
{
public:
  Renderer();
  ~Renderer();

  void			Render() {};

  virtual  void		drawRect(Vector2, int, int) = 0;
private:

};

#endif
