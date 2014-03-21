/*
** itomode.c for my_tar in /home/aslafy_z/rendu/rush_my_tar/etape_2
**
** Made by Zadkiel Aslafy-Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Sun Dec  1 10:56:03 2013 Zadkiel Aslafy-Aharonian
** Last update Sun Dec  1 10:59:31 2013 Zadkiel Aslafy-Aharonian
*/

#include "my_tar.h"

mode_t	itomode_next(int ua, int ga, int oa)
{
  mode_t uam;
  mode_t gam;
  mode_t oam;

  (ua == 7) ? uam = S_IRWXU : 1;
  (ua == 6) ? uam = S_IRUSR | S_IWUSR : 1;
  (ua == 5) ? uam = S_IRUSR | S_IXUSR : 1;
  (ua == 4) ? uam = S_IRUSR : 1;
  (ua == 3) ? uam = S_IWUSR | S_IXUSR : (ua == 2) ? uam = S_IWUSR : 1;
  (ua == 1) ? uam = S_IXUSR : (ua > 7 && ua < 1) ? uam = 0 : 1;
  (ga == 7) ? gam = S_IRWXG : 1;
  (ga == 6) ? gam = S_IRGRP | S_IWGRP : 1;
  (ga == 5) ? gam = S_IRGRP | S_IXGRP : 1;
  (ga == 4) ? gam = S_IRGRP : 1;
  (ga == 3) ? gam = S_IWGRP | S_IXGRP : 1;
  (ga == 2) ? gam = S_IWGRP : 1;
  (ga == 1) ? gam = S_IXGRP : (ga > 7 && ga < 1) ? gam = 0 : 1;
  (oa == 7) ? oam = S_IRWXO : 1;
  (oa == 6) ? oam = S_IROTH | S_IWOTH : 1;
  (oa == 5) ? oam = S_IROTH | S_IXOTH : 1;
  (oa == 4) ? oam = S_IROTH : 1;
  (oa == 3) ? oam = S_IWOTH | S_IXOTH : 1;
  (oa == 2) ? oam = S_IWOTH : 1;
  (oa == 1) ? oam = S_IXOTH : (oa > 7 && oa < 1) ? oam = 0 : 1;
  return (uam | gam | oam);
}

mode_t	itomode(int mode)
{
  int ua;
  int ga;
  int oa;

  if (mode >= 0 && mode <= 777)
    {
      oa = mode % 10;
      mode /= 10;
      ga = mode % 10;
      mode /= 10;
      ua = mode;
    }
  else
    return (-1);
  if (oa > 7 || ga > 7 || ua > 7)
    return (-1);
  return (itomode_next(ua, ga, oa));
}
