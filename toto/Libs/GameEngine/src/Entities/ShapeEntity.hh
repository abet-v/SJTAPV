#ifndef SHAPEENTITY_H
#define SHAPEENTITY_H

#include "BaseEntity.hh"
#include "Core/CoreServices.hh"

class			ShapeEntity : public BaseEntity
{
public:
  ShapeEntity(int shapeType, int size);

  void				Render();
  virtual void			Update(){};

  void				setColor(int color);
  static const int		SHAPE_RECT = 1;
  static const int		SHAPE_CIRCLE = 2;

private:

  int				size_;
  int				shapeType_;
  int				color_;
};


#endif
