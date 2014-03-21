#include "NibblerCore.hh"

int			main()
{
  NibblerCore		*app;

  app = new NibblerCore();

  while(app->Update()) {}
  return (0);
}

