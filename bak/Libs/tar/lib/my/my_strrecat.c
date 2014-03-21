/*
** my_strrecat.c for lib in /home/aslafy_z/rendu/Piscine-C-lib/my
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Tue Oct  8 09:53:29 2013 Zadkiel Aslafy Aharonian
** Last update Fri Nov 15 23:34:27 2013 Zadkiel Aslafy Aharonian
*/

#include <stdlib.h>
#include "my.h"

char	*my_strrecat(char *str1, char *str2)
{
  char	*str;
  int	dest_len;

  dest_len = my_strlen(str1) + my_strlen(str2);
  if ((str = malloc(sizeof(char) * (dest_len + 1))) == NULL)
    return (NULL);
  my_strcpy(str, str1);
  my_strcat(str, str2);
  str[dest_len] = 0;
  return (str);
}
