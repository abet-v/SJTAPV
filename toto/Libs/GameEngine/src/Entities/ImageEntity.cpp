#include "ImageEntity.hh"
#include <iostream>

ImageEntity::ImageEntity(std::string fileName) : BaseEntity()
{
  this->image_ = new Image(fileName);
}

void    ImageEntity::Render()
{
  Renderer *renderer;

  renderer = CoreServices::getInstance()->getRenderer();
  renderer->drawImage(this->image_, this->position_);
}


