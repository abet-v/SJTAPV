#ifndef __SIMPLE_WINDOW_H__
#define __SIMPLE_WINDOW_H__

#include "BaseWindow.hh"

#include <list>
#include <iostream>
#include <string>
#include <string.h>
#include "mlx_int.h"
#include "mlx.h"



//class		BaseWindow;
// class		MLXImage;

class			SimpleWindow : public BaseWindow
{

private:
//  std::list<XEvent>	_events;
t_xvar		*xvar_;
public:
SimpleWindow();
SimpleWindow(const t_xvar *xvar, const unsigned int width, const unsigned int height, const std::string &title);

  ~SimpleWindow();

  // void			PutImage(const MLXImage *, const int, const int);
  // void			PutImage(const MLXImage *);
  // void			MoveWindow(const int, const int);
  // void			ExitHook();
  // void			NewHook(const int, const int);
  // void			ApplyHook();
  // std::list<XEvent>	GetEvents();

  // int			Height() const;
  // int			Width() const;
  // t_win_list		*Win();
};

// #include "MLXImage.hh"


#endif
