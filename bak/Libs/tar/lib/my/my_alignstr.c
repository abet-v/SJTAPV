/*
** my_alignstr.c for lib in /home/aslafy_z/epitech/Lib/my
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Sat Nov 23 15:41:04 2013 Zadkiel Aslafy Aharonian
** Last update Tue Nov 26 15:20:45 2013 Zadkiel Aslafy Aharonian
*/

#include <stdlib.h>
#include "my.h"

char	*my_alignstr(char *str, char c, int max, int direction)
{
  int	i;
  int	len;
  char	*tmp;

  i = 0;
  len = my_strlen(str);
  if ((tmp = malloc(sizeof(char) * max + 2)) == NULL)
    return (NULL);
  my_memset(tmp, c, max);
  if (direction == MY_LEFT)
    while (i < len)
      tmp[i] = str[i++];
  else if (direction == MY_RIGHT)
    while (i < len)
      tmp[max - len + i] = str[i++];
  tmp[max] = 0;
  return (tmp);
}
