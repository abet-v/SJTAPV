
#ifndef __MLXIMAGE_H__
#define __MLXIMAGE_H__

#include <iostream>
#include <string>
#include <strings.h>
#include "mlx_int.h"
#include "mlx.h"
#include <cmath>

class		MLXImage
{

private:
  t_img		*_img;
  int		*_data;
  t_xvar	*_xvar;

  t_img		*ResizeImage(int width, int height);

public:

  MLXImage(t_xvar *xvar, const int width, const int height);
  MLXImage(t_xvar *xvar, const std::string &path);
  MLXImage(t_xvar *xvar, const std::string &path, const int width, const int height);
  ~MLXImage();

  bool		PutPixel(const int, const int, const int);
  void          PutImage(const MLXImage *image, int x, int y, int rotate);
  void          PutImage(const int *data, int width, int height, int x, int y, int rotate);
  void		Clear();
  void		Clear(const int);

  t_img		*Image() const;
  int		*Data() const;
  int		Width() const;
  int		Height() const;
  int		GetPixel(const int) const;
  int		GetPixel(const int, const int) const;
};

#endif
