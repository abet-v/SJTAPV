#ifndef SCENEMANAGER__H
#define SCENEMANAGER__H

#include <vector>

class			Scene;

class			SceneManager
{
public:
  SceneManager();
  ~SceneManager();

  void			Update();
  void			Render();

  void			addScene(Scene *);
  void			removeScene(Scene *);
private:
  std::vector<Scene*>	scenes_;
};

#include "Scene.hh"


#endif
