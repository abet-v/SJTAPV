#include "SoundManager.hh"

SoundManager::SoundManager()
{
  FMOD::Sound		*test;

  this->channel_ = 0;
  FMOD::System_Create(&this->system_);
  this->system_->setOutput(FMOD_OUTPUTTYPE_ALSA);
  this->system_->init(32, FMOD_INIT_NORMAL, 0);
  this->system_->createSound("./test.wav", FMOD_SOFTWARE, 0, &test);

  // this->addSound("pan", test);
}

SoundManager::~SoundManager()
{
  unsigned int		i;

  i = 0;
  while (i < this->sounds_.size())
    {
      delete this->sounds_[i];
      i++;
    }
  this->sounds_.clear();
}

void		SoundManager::addSound(Sound *sound)
{
  // FMOD::Sound		*tmp;

  // this->system_->createSound(path.c_str(), FMOD_SOFTWARE, 0, &tmp);

  // this->sounds_.insert(name.c_str(), tmp);

  this->sounds_.push_back(sound);
}

void		SoundManager::removeSound(Sound *sound)
{
  unsigned int	i;

  i = 0;
  while (i < this->sounds_.size())
    {
      if (this->sounds_[i] == sound)
  	{
  	  this->sounds_.erase(this->sounds_.begin() + i);
  	  return;
  	}
      i++;
    }
}

FMOD::System	*SoundManager::getSoundSystem()
{
  return (this->system_);
}

FMOD::Channel	**SoundManager::getSoundChannel()
{
  return (&this->channel_);
}
