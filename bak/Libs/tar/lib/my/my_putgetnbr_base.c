/*
** my_putgetnbr_base.c for lib in /home/aslafy_z/rendu/Piscine-C-Jour_lib/my
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Wed Oct  9 15:35:44 2013 Zadkiel Aslafy Aharonian
** Last update Sun Oct 27 08:13:12 2013 Zadkiel Aslafy Aharonian
*/

#include <stdlib.h>
#include "my.h"

char	*my_putgetnbr_base_m(int nbr, char *base, char *str, int i)
{
  int   modulo;
  int   divide;
  int   base_size;

  if (nbr < 0)
    {
      nbr = -nbr;
      str[0] = '-';
    }
  base_size = my_strlen(base);
  modulo = nbr % base_size;
  if (nbr >= base_size)
    {
      divide = nbr / base_size;
      str[i] = base[modulo];
      my_putgetnbr_base_m(divide, base, str, i - 1);
    }
  else
    {
      str[i] = base[modulo];
    }
  return (str);
}

char	*my_putgetnbr_base(int nbr, char *base)
{
  int	to_allocate;
  int	temp;
  int	base_size;
  char	*to_return;
  int	i;

  to_allocate = 0;
  temp = nbr;
  if (nbr < 0)
    {
      temp = -temp;
      to_allocate = 1;
    }
  base_size = my_strlen(base);
  while (temp > 0)
    {
      temp = temp / base_size;
      to_allocate = to_allocate + 1;
    }
  if (to_allocate == 0)
    to_allocate = 1;
  my_put_nbr(to_allocate);
  to_return = malloc(to_allocate * sizeof(char));
  return (my_putgetnbr_base_m(nbr, base, to_return, to_allocate - 1));
}
