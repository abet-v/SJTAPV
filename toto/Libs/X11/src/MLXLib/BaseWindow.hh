
#ifndef __BASEWINDOW_H__
#define __BASEWINDOW_H__

#include "mlx_int.h"
#include "mlx.h"

class		BaseWindow
{
  typedef struct  s_event_list
  {
    int           mask;
    int           (*callback)();
    void          *param;
  }t_event_list;

protected:
  Display		*display_;
  Window		window_;
  BaseWindow		*parent_;
  unsigned int		width_;
  unsigned int		height_;
  GC			gc_;

public:

  BaseWindow();
  virtual ~BaseWindow();
  virtual void Show();
  virtual void Hide();
  virtual void Create();
  virtual void Destroy();
  virtual void Refresh();
  virtual bool Move(const int x, const int y);
  virtual bool Resize(const int width, const int height);

  virtual void OnExposeEvent();

  virtual void OnButtonEvent(const int x, const int y);

  virtual void OnEnterEvent(const int x, const int y);
  virtual void OnLeaveEvent(const int x, const int y);

  virtual void OnKeyPressEvent(const int keycode);
  virtual void OnKeyReleaseEvent(const int keycode);


  virtual void OnShow();
  virtual void OnHide();
  virtual void OnCreate();
  virtual void OnDestroy();

  Display	*GetDisplay();
  Window	GetWindow();

  unsigned int	GetWidth() const;
  unsigned int	GetHeight() const;

  t_event_list	eventMasks_[MLX_MAX_EVENT];

  bool		Create(Display *display,
		       Window parent,
		       int x, int y,
		       unsigned int width, unsigned int height,
		       unsigned int border_width,
		       int depth,
		       unsigned int type_class,
		       Visual *Visual,
		       unsigned long valuemask,
		       XSetWindowAttributes *attributes);
    
    };

#endif
