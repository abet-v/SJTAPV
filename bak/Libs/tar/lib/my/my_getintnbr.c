/*
** my_getintnbr.c for lib in /home/aslafy_z/rendu/Piscine-C-Jour_lib/my
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Wed Oct  9 15:35:44 2013 Zadkiel Aslafy Aharonian
** Last update Tue Nov 26 05:33:29 2013 Zadkiel Aslafy Aharonian
*/

#include <stdlib.h>
#include <limits.h>
#include "my.h"

char   	*my_getintnbr(int n)
{
  int	div;
  char	*str;
  int	i;

  i = 0;
  div = 1;
  if ((str = malloc(sizeof(char) * 12)) == NULL)
    return (NULL);
   if (n < 0 && n > INT_MIN)
     {
       str[i++] = '-';
       n = -n;
     }
  while ((n / div) >= 10)
    div = div * 10;
  while (div >= 1)
    {
      str[i++] = n / div + '0';
      n = n - (str[i - 1] - '0') * div;
      div /= 10;
    }
  str[i] = 0;
  return ((n == INT_MIN) ? "-2147483648" : str);
}
