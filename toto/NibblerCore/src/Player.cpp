#include "Player.hh"
#include <iostream>

Player::Player(const char *fileName) : ImageEntity(std::string(fileName))
{
}

void		Player::onCreate()
{
  this->angle_ = 0;
  this->setPosition(320, 220);
  this->sound_ = new Sound("Resources/sounds/test.wav");
  this->jump_ = 0;
}

void		Player::shoot()
{
  static int	last_shoot;

  if (CoreServices::getInstance()->getCore()->getTicks() - last_shoot > 500)
    {
      this->addChild(new Bullet("Resources/images/apple.png"));
      this->sound_->play(false);
      last_shoot = CoreServices::getInstance()->getCore()->getTicks();
    }
}

double		Player::getAngle()
{
  return (this->angle_);
}

void		Player::Update()
{
  CoreInput		*input;

  input = CoreServices::getInstance()->getCore()->getInput();
  if (input->getKeyState(114))
    {
      this->TranslateX(+0.4 * Player::PlayerSpeed);
      this->angle_ = 0;
    }
  if (input->getKeyState(113))
    {
      this->TranslateX(-0.4 * Player::PlayerSpeed);
      this->angle_ = 180;
    }
  if (jump_ < 0)
    {
      this->TranslateY(jump_ / 10 * Player::PlayerSpeed);
      jump_ += 1;
    }
  else if (getPositionY() < 150)
    {
      // if (jump_ <= 0)
      // 	jump_ = -10;
      this->TranslateY(1 * Player::PlayerSpeed);
      // jump_++;
    }
  else if (input->getKeyState(116))
    this->jump_ = -10;
  // else
  //   this->setColor(0xFFFF00);

  if (input->getKeyState(65))
    this->shoot();
}
