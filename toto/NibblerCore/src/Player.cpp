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
  this->addChild(new Bullet("Resources/images/apple.png"));
  this->sound_->play(false);
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
    this->TranslateX(+1 * Player::PlayerSpeed);
  if (input->getKeyState(113))
    this->TranslateX(-1 * Player::PlayerSpeed);

  // if (input->getKeyState(116))
  //   this->TranslateY(+1 * Player::PlayerSpeed);
  // if (input->getKeyState(111))
  //   this->TranslateY(-1 * Player::PlayerSpeed);

  
  // if (input->getKeyState(114))
  //   this->angle_ -= 0.1;
  // if (input->getKeyState(113))
  //   this->angle_ += 0.1;


  
  // if (input->getKeyState(116))
  //   {
  //     this->TranslateY(+(sin(this->angle_) * Player::PlayerSpeed));
  //     this->TranslateX(-(cos(this->angle_) * Player::PlayerSpeed));
  //   }
  // if (input->getKeyState(111))
  //   {
  //     this->TranslateY(-(sin(this->angle_) * Player::PlayerSpeed));
  //     this->TranslateX(+(cos(this->angle_) * Player::PlayerSpeed));
  //   }
  if (jump_ >= 0)
    {
      this->TranslateY(-0.4 * Player::PlayerSpeed);
      jump_ -= 0.4;
    }
  else if (getPositionY() < 150)
    {
      this->TranslateY(+0.4 * Player::PlayerSpeed);
    }
  else if (input->getKeyState(65))
    this->jump_ = 10;
  // else
  //   this->setColor(0xFFFF00);

  // if (input->getKeyState(65))
  //   this->shoot();
}
