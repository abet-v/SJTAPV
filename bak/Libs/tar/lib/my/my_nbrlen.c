/*
** my_nbrlen.c for lib in /home/aslafy_z/rendu/PSU_2013_my_printf
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Wed Nov 13 17:46:24 2013 Zadkiel Aslafy Aharonian
** Last update Tue Nov 26 05:53:53 2013 Zadkiel Aslafy Aharonian
*/

#include "my.h"

int	my_nbrlen(int nbr)
{
  return (my_strlen(my_getintnbr(nbr)));
}
