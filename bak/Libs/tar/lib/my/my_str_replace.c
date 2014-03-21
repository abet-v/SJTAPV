/*
** my_str_replace.c for lib in /home/aslafy_z/rendu/Piscine-C-lib/my
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Fri Oct 25 13:29:09 2013 Joan
** Last update Sun Nov 10 17:54:38 2013 Zadkiel Aslafy Aharonian
*/
#include <stdlib.h>
#include "my.h"

int	my_strpos(char *haystack, char *needle)
{
  char	*p;

  p = my_strstr(haystack, needle);
  if (p)
    return (p - haystack);
  return (-1);
}

char    *my_str_replace(char *search, char *replace, char *str)
{
  char  *ret;
  int   stop;
  int   i;
  int   j;
  int   s_s;
  int   s_r;
  int   index;

  i = 0;
  j = 0;
  index = 0;
  stop = 0;
  s_s = my_strlen(search);
  s_r = my_strlen(replace);
  if ((index = my_strpos(str, search)) < -1)
    return (str);
  ret = malloc(sizeof(char) * (my_strlen(str) - s_s + my_strlen(search) + 1));
  my_strncat(ret, str, index);
  i = index;
  j = i;
  ret[j] = 0;
  my_strcat(ret, replace);
  i = i + s_s;
  my_strcat(ret, &str[i]);
  return (ret);
}
