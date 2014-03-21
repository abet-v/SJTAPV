#ifndef SPRITEENTITY_H
#define SPRITEENTITY_H

#include "BaseEntity.hh"
#include "Image.hh"
#include <string>
#include "Core/CoreServices.hh"

class			SpriteEntity : public BaseEntity
{
public:
  SpriteEntity();

  void				Render();
  virtual void			Update(){};

private:
  int				frameRate_;
  std::vector<Image*>		images_;
  Image				*image_;
};


#endif
