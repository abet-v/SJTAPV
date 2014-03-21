/*
** my_char_to_str.c for lib in /home/aslafy_z/rendu/PSU_2013_my_printf
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Wed Nov 13 17:35:48 2013 Zadkiel Aslafy Aharonian
** Last update Fri Nov 15 21:42:29 2013 Zadkiel Aslafy Aharonian
*/

#include <stdlib.h>

char	*my_char_to_str(char c)
{
  char	*result;

  if ((result = malloc(2 * sizeof(char))) == NULL)
    return (NULL);
  result[0] = c;
  result[1] = 0;
  return (result);
}
