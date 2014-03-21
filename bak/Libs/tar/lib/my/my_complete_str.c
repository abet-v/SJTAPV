/*
** my_complete_str.c for lib in /home/aslafy_z/rendu/PSU_2013_my_printf
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Wed Nov 13 17:37:05 2013 Zadkiel Aslafy Aharonian
** Last update Wed Nov 13 17:37:16 2013 Zadkiel Aslafy Aharonian
*/

#include <stdlib.h>
#include "my.h"

char	*my_complete_str(char *str, char c, int n)
{
  char	*result;
  int	len;
  int	i;

  len = my_strlen(str);
  i = -1;
  if (n - len > 0)
    {
      if ((result = malloc((n + len) * sizeof(char))) == NULL)
	return (NULL);
      while (++i + len < n)
	my_strccat(result, c);
      my_strcat(result, str);
      return (result);
    }
  return (str);
}
