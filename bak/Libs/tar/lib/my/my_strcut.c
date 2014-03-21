/*
** my_strcut.c for bistromathique in /home/aslafy_z/rendu/Bistro/srcs
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Sat Nov  9 14:40:00 2013 Zadkiel Aslafy Aharonian
** Last update Tue Nov 12 12:00:32 2013 Zadkiel Aslafy Aharonian
*/

#include <stdlib.h>
#include "my.h"

char	*my_strcut(char *str, int cut)
{
  int	i;
  char	*result;

  if ((result = malloc(sizeof(char) * (cut + 1))) == 0)
    return (0);
  i = 0;
  while (i < cut)
    {
      result[i] = str[i];
      i = i + 1;
    }
  return (result);
}
