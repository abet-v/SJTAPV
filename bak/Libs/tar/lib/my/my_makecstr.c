/*
** my_makecstr.c for lib in /home/aslafy_z/rendu/PSU_2013_my_printf
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Sun Nov 17 23:16:38 2013 Zadkiel Aslafy Aharonian
** Last update Sat Nov 23 18:14:47 2013 Zadkiel Aslafy Aharonian
*/

#include <stdlib.h>
#include "my.h"

char	*my_makecstr(char c, int n)
{
  char	*str;
  int	i;

  if (n < 0)
    n = 0;
  i = 0;
  if ((str = malloc(sizeof(char) * n + 1)) == NULL)
    return (NULL);
  while (i < n)
    str[i++] = c;
  str[i] = 0;
  return (str);
}
