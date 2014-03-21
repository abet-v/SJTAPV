#ifndef IMAGE_H
#define IMAGE_H

#include "Core/CoreServices.hh"

#include "stb_image.hh"
#include <math.h>

#include <iostream>

class			Image
{
public:
  Image(std::string fileName);

  int			getHeight();
  int			getWidth();
  int			*getData();

private:
  int			width_;
  int			height_;
  int			bitdepth_;

  char			*data_;
};


#endif
