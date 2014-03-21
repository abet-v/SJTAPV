#ifndef SOUNDMANAGER__H
#define SOUNDMANAGER__H

#include <vector>
#include <string>
#include <map>

#include "Include/fmod.hpp"
#include "Include/wincompat.h"

class				Sound;

class				SoundManager
{
public:
  SoundManager();
  ~SoundManager();

  void				addSound(Sound *sound);
  void				removeSound(Sound *sound);

  FMOD::System			*getSoundSystem();
  FMOD::Channel			**getSoundChannel();
private:
  std::vector<Sound*>		sounds_;

  FMOD::System			*system_;
  FMOD::Channel			*channel_;

};

#include "Sound.hh"

#endif
