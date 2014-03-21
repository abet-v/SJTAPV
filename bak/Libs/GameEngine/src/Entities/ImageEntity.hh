#ifndef IMAGEENTITY_H
#define IMAGEENTITY_H

#include "BaseEntity.hh"
#include "Image.hh"
#include <string>
#include "Core/CoreServices.hh"

class			ImageEntity : public BaseEntity
{
public:
  ImageEntity(std::string fileName);

  void				Render();
  virtual void			Update(){};

private:

Image				*image_;
};


#endif
