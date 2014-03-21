#ifndef CLOCK_H
#define CLOCK_H

#include "Core/Core.hh"
#include <math.h>

class			Clock
{
public:
  Clock();

  unsigned int		Update();
private:
  unsigned int		firstTick_;
  unsigned int		curTick_;

};


#endif
