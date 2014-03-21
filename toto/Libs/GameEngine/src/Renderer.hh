#ifndef RENDERER_HH
#define RENDERER_HH

#include "Vector2.hh"

class			Image;

class			Renderer
{
public:
  Renderer();
  ~Renderer();

  void			Render() {};

  virtual void		clearScreen(int) = 0;
  virtual void		drawRect(Vector2, int, int) = 0;
  virtual void		drawImage(Image *, Vector2) = 0;
private:

};

// #include "Image.hh"

#endif
