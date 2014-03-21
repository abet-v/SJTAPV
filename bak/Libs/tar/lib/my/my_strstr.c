/*
** my_strstr.c for day 06 in /home/aslafy_z/rendu/Piscine-C-Jour_06
** 
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
** 
** Started on  Mon Oct  7 09:50:01 2013 Zadkiel Aslafy Aharonian
** Last update Mon Oct  7 22:43:06 2013 Zadkiel Aslafy Aharonian
*/
#include <string.h>

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	x;

  i = 0;
  while (str[i] != '\0')
    {
      x = 0;
      while (str[i + x] == to_find[x] && to_find[x] != '\0')
	{
	  x = x + 1;
	}
      if (to_find[x] == '\0')
	{
	  return (&str[i]);
	}
      i = i + 1;
    }
  return (NULL);
}
