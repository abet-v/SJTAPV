#ifndef BASEENTITY_H
#define BASEENTITY_H

#include "Events/EventDispatcher.hh"
#include "Vector2.hh"
#include "Renderer.hh"
#include <vector>


class			BaseEntity : public EventDispatcher
{
public:
  BaseEntity();

  virtual void			Render(){};
  virtual void			Update(){};

  virtual void			onCreate(){};

  void				doUpdates();
  void				renderChildrens();

  void				addChild(BaseEntity *entity);
  void				setParentEntity(BaseEntity *parent);

  void				setRenderer(Renderer *renderer);

  void				Translate(const Vector2 &pos);
  void				Translate(int x, int y);
  void				TranslateX(int x);
  void				TranslateY(int y);

  Vector2			&getPosition();
  int				getPositionY();
  int				getPositionX();

  void				setPosition(const Vector2 &pos);
  void				setPosition(int x, int y);
  void				setPositionY(int y);
  void				setPositionX(int x);

protected:

  Vector2			position_;

  Renderer			*renderer_;
  std::vector<BaseEntity*>	childs_;
  BaseEntity			*parentEntity_;

};


#endif
