#include "Bullet.hh"
#include <iostream>

void		Bullet::onCreate()
{
  this->setPosition(this->parentEntity_->getPosition());
  this->angle_ = ((Player*)this->parentEntity_)->getAngle();
  std::cout << "Angle : " << this->angle_ << std::endl;
  // this->setColor(0x0000FF);
}

void		Bullet::Update()
{
  this->TranslateY(-(sin(this->angle_*3.14/180) * Bullet::BulletSpeed));
  this->TranslateX(+(cos(this->angle_*3.14/180) * Bullet::BulletSpeed));
}
