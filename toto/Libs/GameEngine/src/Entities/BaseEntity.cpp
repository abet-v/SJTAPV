#include "BaseEntity.hh"

#include <iostream>

BaseEntity::BaseEntity()
{
}

void		BaseEntity::doUpdates()
{
  unsigned int	i;

  this->Update();
  i = 0;
  while (i < this->childs_.size())
    {
      this->childs_[i]->doUpdates();
      i++;
    }
}

void		BaseEntity::renderChildrens()
{
  unsigned int	i;

  i = 0;
  while (i < this->childs_.size())
    {
      this->childs_[i]->doUpdates();
      this->childs_[i]->Render();
      this->childs_[i]->renderChildrens();
      i++;
    }
}

void		BaseEntity::setParentEntity(BaseEntity *parent)
{
  this->parentEntity_ = parent;
}

void		BaseEntity::setRenderer(Renderer *renderer)
{
  this->renderer_ = renderer;
}

void		BaseEntity::addChild(BaseEntity *entity)
{
  entity->setRenderer(this->renderer_);
  entity->setParentEntity(this);
  entity->onCreate();
  this->childs_.push_back(entity);
}

void		BaseEntity::setPosition(const Vector2 &pos)
{
  this->position_.x = pos.x;
  this->position_.y = pos.y;
}

void		BaseEntity::setPosition(int x, int y)
{
  this->position_.x = x;
  this->position_.y = y;
}

void		BaseEntity::setPositionX(int x)
{
  this->position_.x = x;
}

void		BaseEntity::setPositionY(int y)
{
  this->position_.y = y;
}

void		BaseEntity::Translate(const Vector2 &pos)
{
  this->position_.x += pos.x;
  this->position_.y += pos.y;
}

void		BaseEntity::Translate(int x, int y)
{
  this->position_.y += y;
  this->position_.x += x;
}
void		BaseEntity::TranslateX(int x)
{
  this->position_.x += x;
}

void		BaseEntity::TranslateY(int y)
{
  this->position_.y += y;
}


Vector2		&BaseEntity::getPosition()
{
  return (this->position_);
}

int		BaseEntity::getPositionX()
{
  return (this->position_.x);
}

int		BaseEntity::getPositionY()
{
  return (this->position_.y);
}
