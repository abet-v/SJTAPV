/*
** my_getintnbr.c for lib in /home/aslafy_z/rendu/Piscine-C-Jour_lib/my
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Wed Oct  9 15:35:44 2013 Zadkiel Aslafy Aharonian
** Last update Wed Nov 13 20:36:46 2013 Zadkiel Aslafy Aharonian
*/

#include <stdlib.h>
#include "my.h"

char		*my_getuintnbr(unsigned int n)
{
  unsigned int	div;
  unsigned int	c;
  char		*str;
  unsigned int	i;

  i = 0;
  div = 1;
  if ((str = malloc(sizeof(char) * 10)) == NULL)
    return (NULL);
  if (n <= 9)
    return (my_strccat(str, n + '0'));
  while ((n / div) >= 10)
    div = div * 10;
  while (div >= 1)
    {
      c = n / div;
      n = n - c * div;
      div = div / 10;
      str[i++] = c + '0';
    }
  str[i + 1] = 0;
  return (str);
}
