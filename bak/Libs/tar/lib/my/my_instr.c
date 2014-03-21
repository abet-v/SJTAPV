/*
** my_instr.c for lib in /home/aslafy_z/rendu/PRINTF
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Sat Nov  2 21:26:41 2013 Zadkiel Aslafy Aharonian
** Last update Sat Nov  2 21:28:36 2013 Zadkiel Aslafy Aharonian
*/

#include "my.h"

int	my_instr(char *str, char c)
{
  int	i;

  i = 0;
  while (str && str[i])
    {
      if (str[i] == c)
	return (1);
      i++;
    }
  return (0);
}