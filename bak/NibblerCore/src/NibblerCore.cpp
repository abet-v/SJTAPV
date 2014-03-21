
#include "NibblerCore.hh"

NibblerCore::NibblerCore()
{
  this->loadCore();

  this->core_->getInput()->addEventListener(this, InputEvent::EVENT_KEYUP);

  this->scene_ = new Scene();

  this->player_ = new Player("Resources/images/player.png");


  this->scene_->addChild(this->player_);
}

NibblerCore::~NibblerCore()
{
  delete this->scene_;
  delete this->core_;
  dlclose(this->dlHandle_);
}

bool			NibblerCore::loadCore()
{
  Core			*(*createObject)(int, int, bool);
  const char            *dlsym_error;

  this->dlHandle_ = dlopen("./libNibblerX11.so", RTLD_NOW | RTLD_LOCAL);
  if (!this->dlHandle_)
    {
      std::cerr << "dlopen() : " << dlerror() << std::endl;
      return (false);
    }

  createObject = *(Core*(*)(int, int, bool))dlsym(this->dlHandle_, "createObject");

  dlsym_error = dlerror();
  if (dlsym_error)
    {
      std::cerr << "Cannot load symbol 'createObject': " << dlsym_error << std::endl;
      dlclose(this->dlHandle_);
      return (false);
    }

  this->core_ = createObject(640, 480, 0);
  return (true);
}

void			NibblerCore::handleEvent(Event *event)
{
  InputEvent		*inputEvent;

  if (event->getDispatcher() == this->core_->getInput())
    {
      inputEvent = (InputEvent*)event;
      if (inputEvent->getEventCode() == InputEvent::EVENT_KEYUP)
	{
	  if (inputEvent->getKey() == 9)
	      this->core_->shutdown();
	  //std::cout << "Key : " << inputEvent->getKey() << std::endl;
	}
    }
}

bool			NibblerCore::Update()
{
  return (this->core_->updateAndRender());
}
