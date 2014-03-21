#include "ShapeEntity.hh"
#include <iostream>

ShapeEntity::ShapeEntity(int shapeType, int size = 0) : BaseEntity()
{
  this->shapeType_ = shapeType;
  this->size_ = size;
}

void		ShapeEntity::setColor(int color)
{
  this->color_ = color;
}

void		ShapeEntity::Render()
{
  Renderer *renderer;

  renderer = CoreServices::getInstance()->getRenderer();
  switch (this->shapeType_)
    {
    case SHAPE_RECT:
      renderer->drawRect(this->position_, this->size_, this->color_);
      break;
    }
}

