/*
** my_charcat.c for bistromathique in /home/aslafy_z/rendu/Bistro/srcs
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Sat Nov  9 14:31:24 2013 Zadkiel Aslafy Aharonian
** Last update Tue Nov 12 11:56:05 2013 Zadkiel Aslafy Aharonian
*/

#include "my.h"

char	*my_strccat(char *dest, char c)
{
  int	dest_len;

  dest_len = my_strlen(dest);
  dest[dest_len] = c;
  dest[dest_len + 1] = '\0';
  return (dest);
}
