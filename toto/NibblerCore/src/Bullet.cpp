#include "Bullet.hh"
#include <iostream>

void		Bullet::onCreate()
{
  this->setPosition(this->parentEntity_->getPosition());
  this->angle_ = ((Player*)this->parentEntity_)->getAngle();
  // this->setColor(0x0000FF);
}

void		Bullet::Update()
{
  this->TranslateY(-(sin(this->angle_) * Bullet::BulletSpeed));
  this->TranslateX(+(cos(this->angle_) * Bullet::BulletSpeed));
}
