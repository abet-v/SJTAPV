
#include "SimpleWindow.hh"


SimpleWindow::SimpleWindow(const t_xvar *xvar, const unsigned int width, const unsigned int height, const std::string &title)
{

  XSetWindowAttributes  xswa;
  XGCValues             xgcv;

  xswa.background_pixel = 0;
  xswa.border_pixel = -1;
  xswa.colormap = this->xvar_->cmap;
  xswa.event_mask = 0xFFFFFF;  /* all events */


  this->Create(this->display_, this->xvar_->root, 0, 0, width, height,
	       0, CopyFromParent, InputOutput, xvar->visual,
	       CWEventMask | CWBackPixel | CWBorderPixel | CWColormap,
	       &xswa);

  XStoreName(this->display_, this->window_, const_cast<char *>(title.c_str()));

  xgcv.foreground = -1;
  xgcv.function = GXcopy;
  xgcv.plane_mask = AllPlanes;
  this->gc_ = XCreateGC(this->display_, this->window_,
			GCFunction | GCPlaneMask | GCForeground,
			&xgcv);

  memset(&(this->eventMasks_), 0, sizeof(this->eventMasks_));
  XMapRaised(this->xvar_->display, this->window_);
  //mlx_int_wait_first_expose(xvar,new_win->window);
}

SimpleWindow::SimpleWindow()
{

}
