
#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

class					GameState
{
public:
  virtual ~GameState(void) {};

  virtual void HandleInput(void) = 0;
  virtual void Update(void) = 0;
  virtual void Render(void) = 0;
  virtual void onEnter(void) = 0;
  virtual void onExit(void) = 0;
  virtual void Initialize(void) = 0;
  virtual void Initialize(void *) = 0;


};

#endif /* __GAMESTATE_H__ */
