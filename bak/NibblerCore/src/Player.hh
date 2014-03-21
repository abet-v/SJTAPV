#ifndef PLAYER_H
#define PLAYER_H

#include "Entities/ImageEntity.hh"
#include "Core/CoreServices.hh"
#include "Bullet.hh"
#include "Sound/Sound.hh"
#include "Image.hh"
#include <math.h>
#include <string>

class			Player : public ImageEntity
{
public:
  Player(const char *fileName);

  void			onCreate();
  void			Update();


  double		getAngle();
  static const int	PlayerSpeed = 8;
  
private:
  void			shoot();


  double		jump_;
  double		angle_;
  Sound			*sound_;
};


#endif
