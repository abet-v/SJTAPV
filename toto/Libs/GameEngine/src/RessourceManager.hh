#ifndef RESSOURCEMANAGER__H
#define RESSOURCEMANAGER__H

#include <vector>
#include "Core/CoreServices.hh"

class			RessourceManager
{
public:
  RessourceManager();
  ~RessourceManager();

  void			addRessource(int type, void *obj);
  void			removeRessource(void *obj);

  static const int		TYPE_IMAGE = 1;
  static const int		TYPE_SOUND = 1;
};

#endif
