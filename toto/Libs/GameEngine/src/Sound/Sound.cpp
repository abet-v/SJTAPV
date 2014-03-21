#include "Sound.hh"

Sound::Sound(std::string fileName)
{
  this->system_ = CoreServices::getInstance()->getSoundManager()->getSoundSystem();
  this->channel_ = CoreServices::getInstance()->getSoundManager()->getSoundChannel();
  this->system_->createSound("./test.wav", FMOD_SOFTWARE, 0, &this->sound_);
}

void		Sound::play(bool loop)
{
  this->system_->playSound(FMOD_CHANNEL_FREE, this->sound_, false, 0);
  this->system_->update();
}
