/*
** my_strdup.c for day 08 in /home/aslafy_z/rendu/Piscine-C-Jour_08/ex_01
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Wed Oct  9 09:29:32 2013 Zadkiel Aslafy Aharonian
** Last update Tue Nov 26 00:34:46 2013 Zadkiel Aslafy Aharonian
*/
#include <stdlib.h>

char	*my_strdup(char *src)
{
  char	*dest;

  dest = malloc((my_strlen(src) + 1) * sizeof(char));
  if (dest)
    my_strcpy(dest, src);
  return (dest);
}
