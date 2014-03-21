/*
** my_trimstr.c for lib in /home/aslafy_z/rendu/PSU_2013_my_printf
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Sun Nov 17 13:47:15 2013 Zadkiel Aslafy Aharonian
** Last update Sat Nov 23 16:00:10 2013 Zadkiel Aslafy Aharonian
*/

#include "my.h"

char	*my_trimstr(char *str, char c, int direction)
{
  int	i;
  int	len;

  i = -1;
  len = my_strlen(str);
  if (direction == MY_LEFT)
    {
      while (str && str[++i] == c);
      str = &str[i];
    }
  else if (direction == MY_RIGHT)
    {
      while (str && str[--len] == c);
      str[len + 1] = 0;
    }
  return (str);
}
