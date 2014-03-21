/*
** convert_base.c for day 08 in /home/aslafy_z/rendu/Piscine-C-Jour_08/ex_02
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Wed Oct  9 15:35:44 2013 Zadkiel Aslafy Aharonian
** Last update Sun Dec  1 08:37:47 2013 Zadkiel Aslafy-Aharonian
*/

#include <stdlib.h>
#include "my.h"

char	*my_putnbr_convert_base(int nbr, char *base, char *str, int i)
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
      my_putnbr_convert_base(divide, base, str, i - 1);
    }
  else
    {
      str[i] = base[modulo];
    }
  return (str);
}

char	*my_putnbr_convert_base_m(int nbr, char *base)
{
  int	to_allocate;
  int	temp;
  int	base_size;
  char	*to_return;
  int	i;

  if (nbr == 0)
    return (my_char_to_str(base[0]));
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
  to_return = malloc((to_allocate + 1) * sizeof(char));
  return (my_putnbr_convert_base(nbr, base, to_return, to_allocate - 1));
}

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  return (my_putnbr_convert_base_m(my_getnbr_base(nbr, base_from), base_to));
}
