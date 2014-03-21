
#ifndef __MLXWINDOW_H__
#define __MLXWINDOW_H__

#include <list>
#include <iostream>
#include <string>
#include "mlx_int.h"
#include "mlx.h"

class		MLXImage;

class		MLXWindow
{

private:
  t_win_list		*_win;
  t_xvar		*_xvar;
  int			_width;
  int			_height;
  std::list<XEvent>	_events;

public:

  MLXWindow(t_xvar *xvar, const int, const int, const std::string &);
  MLXWindow(t_xvar *xvar, const int, const int);
  ~MLXWindow();

  void			PutImage(const MLXImage *, const int, const int);
  void			PutImage(const MLXImage *);
  void			MoveWindow(const int, const int);
  void			ExitHook();
  void			NewHook(const int, const int);
  void			ApplyHook();
  std::list<XEvent>	GetEvents();

  int			Height() const;
  int			Width() const;
  t_win_list		*Win();
};

#include "MLXImage.hh"

#endif
