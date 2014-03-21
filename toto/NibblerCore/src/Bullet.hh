#ifndef BULLET_H
#define BULLET_H

#include "Entities/ImageEntity.hh"
#include "Core/CoreServices.hh"
#include "Player.hh"
#include <math.h>

class			Bullet : public ImageEntity
{
public:
  Bullet(const char *fileName) : ImageEntity(std::string(fileName)){};

  void			onCreate();
  void			Update();

  static const int	BulletSpeed = 5;

private:
  double		angle_;
};


#endif
