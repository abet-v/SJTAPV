
#include "MLXImage.hh"

MLXImage::MLXImage(t_xvar *xvar, const int width, const int height)
{
  this->_img = (t_img*)mlx_new_image(xvar, width, height);
  if (!this->_img)
    {
      //  throw Error("Fail to created the img");
    }
  this->_data = (int*)this->_img->data;
  this->_xvar = xvar;
}

MLXImage::MLXImage(t_xvar *xvar, const std::string &path)
{
  int		bidon;

  this->_img = ((t_img*)mlx_xpm_file_to_image(xvar, const_cast<char *>(path.c_str()), &bidon, &bidon));
  if (!this->_img)
    {
      //  throw Error("Fail to created the img");
    }
  this->_data = (int*)this->_img->data;
  this->_xvar = xvar;
}

MLXImage::MLXImage(t_xvar *xvar, const std::string &path, const int width, const int height)
{
  int		bidon;

  this->_img = ((t_img*)mlx_xpm_file_to_image(xvar, const_cast<char *>(path.c_str()), &bidon, &bidon));
  if (!this->_img)
    {
      //  throw Error("Fail to created the img");
    }
  this->_data = (int*)this->_img->data;
  this->_xvar = xvar;
  this->ResizeImage(width, height);
}

MLXImage::~MLXImage()
{
  if (this->_xvar->use_xshm)
    {
      shmdt(this->_img->data);
      shmctl(this->_img->shm.shmid,IPC_RMID,0);
    }
  XDestroyImage(this->_img->image);
  XFreePixmap(this->_xvar->display, this->_img->pix);
  free(this->_img);
}

t_img		*MLXImage::ResizeImage(int width, int height)
{
  t_img		*new_img;
  int		*new_data;
  double	width_scale;
  double	height_scale;
  int		x;
  int		y;

  width_scale = this->_img->width / (float)width;
  height_scale = this->_img->height / (float)height;
  new_img = (t_img*)mlx_new_image(this->_xvar, width, height);
  new_data = (int*)new_img->data;
  y = 0;
  while (y < new_img->height)
    {
      x = 0;
      while (x < new_img->width)
	{
	  new_data[y * new_img->width + x] = this->GetPixel(x * width_scale, y * height_scale);
	  x++;
	}
      y++;
    }
  if (this->_xvar->use_xshm)
    {
      shmdt(this->_img->data);
      shmctl(this->_img->shm.shmid,IPC_RMID,0);
    }
  XDestroyImage(this->_img->image);
  XFreePixmap(this->_xvar->display, this->_img->pix);
  free(this->_img);
  this->_img = new_img;
  this->_data = new_data;
  return (_img);
}

bool		MLXImage::PutPixel(const int x, const int y, const int color)
{
  if (color == 0x980088)
    return (true);
  if (!(x < this->_img->width && x >= 0 && y < this->_img->height && y >= 0))
    return (false);
  this->_data[y * (this->_img->width) + x] = color;
  return (true);
}

void            MLXImage::PutImage(const MLXImage *image, int x, int y, int rotate)
{
  int           x_cnt;
  int           y_cnt;
  int		imageWidth;
  int		imageHeight;
  double		a;

  a = rotate;

  imageHeight = image->Height();
  imageWidth = image->Width();
  y_cnt = 0;
  while(y_cnt < imageHeight)
    {
      x_cnt = 0;
      while (x_cnt < imageWidth)
	{

	  this->PutPixel(x + (x_cnt * cos(a) + y_cnt * sin(a)),
			 y + (y_cnt * (cos(a) - x_cnt * sin(a))),
			 image->GetPixel(x_cnt, y_cnt));
	  // switch (rotate)
	  //   {
	  //   case 0:

	  //   case 0:
	  //     this->PutPixel(x + x_cnt, y + y_cnt,
	  // 		     image->GetPixel(x_cnt, y_cnt));
	  //     break;
	  //   case 90:
	  //     this->PutPixel(x + x_cnt, y + y_cnt,
	  // 		     image->GetPixel(y_cnt, x_cnt));
	  //     break;
	  //   case 180:
	  //     this->PutPixel(x + x_cnt, y + y_cnt,
	  // 		     image->GetPixel(imageWidth - x_cnt, imageHeight - y_cnt - 1));
	  //     break;
	  //   case 270:
	  //     this->PutPixel(x + x_cnt, y + y_cnt,
	  // 		     image->GetPixel(imageHeight - y_cnt, imageWidth - x_cnt - 1));
	  //     break;
	  //   }
	  x_cnt++;
	}
      y_cnt++;
    }
}


void		MLXImage::Clear(const int color)
{
  int		i;

  i = 0;
  while (i < this->_img->width * this->_img->height)
    {
      this->_data[i] = color;
      i++;
    }
}

void		MLXImage::Clear()
{
  bzero(this->_data, this->_img->width * this->_img->height);
}

t_img		*MLXImage::Image() const
{
  return (this->_img);
}

int		*MLXImage::Data() const
{
  return (this->_data);
}

int		MLXImage::Width() const
{
  return (this->_img->width);
}

int		MLXImage::Height() const
{
  return (this->_img->height);
}

int		MLXImage::GetPixel(const int i) const
{
  return (this->_data[i]);
}

int		MLXImage::GetPixel(const int x, const int y) const
{
  return (this->_data[y * this->_img->width + x]);
}
