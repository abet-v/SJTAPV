/*
** ee_get_str_from_pos.c for bistromathique in /home/aslafy_z/rendu/Bistro/srcs
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Sat Nov  9 14:45:37 2013 Zadkiel Aslafy Aharonian
** Last update Sun Nov 17 20:55:40 2013 Zadkiel Aslafy Aharonian
*/

#include <stdlib.h>

char	*my_str_getpos(char *str, int pos1, int pos2)
{
  char	*result;
  int	i;

  if ((result = malloc(((pos2 - pos1) + 1) * sizeof(char))) == 0)
    return (NULL);
  i = 0;
  while (str[pos1] && i < (pos2 - pos1))
    {
      result[i] = str[pos1 + i];
      i = i + 1;
    }
  result[i] = 0;
  return (result);
}
