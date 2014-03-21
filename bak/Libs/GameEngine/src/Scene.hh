#ifndef _SCENE_HH
#define _SCENE_HH

#include "Events/EventDispatcher.hh"
#include "Core/CoreServices.hh"
#include "SceneManager.hh"
#include "Entities/BaseEntity.hh"

class Scene : public BaseEntity
{
public:
  Scene();

  void			Render();
  void			Update();

  bool			isEnabled();

private:
  bool			enabled_;
};

#endif
