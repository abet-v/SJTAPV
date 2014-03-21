#ifndef SOUND_H
#define SOUND_H

#include "Core/CoreServices.hh"

#include "Include/fmod.hpp"
#include "Include/wincompat.h"

#include <string>

class			Sound
{
public:
  Sound(std::string fileName);

  void			play(bool loop);
private:
  FMOD::Sound		*sound_;
  FMOD::System		*system_;
  FMOD::Channel		**channel_;

};


#endif
