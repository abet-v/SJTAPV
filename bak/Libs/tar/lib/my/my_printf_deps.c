/*
** my_printf_deps.c for lib in /home/aslafy_z/rendu/Piscine-C-lib/my
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Wed Oct  9 15:35:44 2013 Zadkiel Aslafy Aharonian
** Last update Sun Nov 24 16:52:25 2013 Zadkiel Aslafy Aharonian
*/

#include <stdlib.h>
#include "my.h"

char	*my_putnbr_base_pf_r(t_lui nbr, char *base, char *str, int i)
{
  t_lui	modulo;
  t_lui	divide;
  int	base_size;

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
      my_putnbr_base_pf_r(divide, base, str, i - 1);
    }
  else
    {
      str[i] = base[modulo];
    }
  return (str);
}

char	*my_putnbr_base_pf(t_lui nbr, char *base)
{
  t_lui	to_allocate;
  t_lui	temp;
  int	base_size;
  char	*to_return;

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
  to_return = malloc(to_allocate * sizeof(char));
  return (my_putnbr_base_pf_r(nbr, base, to_return, to_allocate - 1));
}

char	*convert_base_lui_pf(t_lui nbr, char *base_to)
{
  return (my_putnbr_base_pf(nbr, base_to));
}

char	*convert_base_int_pf(int nbr, char *base_to)
{
  return (my_putnbr_convert_base_m(nbr, base_to));
}

char	*convert_base_str_pf(char *nbr, char *base_from, char *base_to)
{
  return (my_putnbr_base_pf(my_getnbr_base(nbr, base_from), base_to));
}
