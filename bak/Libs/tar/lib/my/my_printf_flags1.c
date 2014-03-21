/*
** flags.c for my_printf in /home/aslafy_z/rendu/PSU_2013_my_printf
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Mon Nov 11 23:30:47 2013 Zadkiel Aslafy Aharonian
** Last update Sun Nov 24 15:11:01 2013 Zadkiel Aslafy Aharonian
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#define  __MY_PRINTF_FLAGS__
#include "my_printf.h"

char	*flag_perc(t_pf *pf)
{
  return (my_char_to_str('%'));
}

char	*flag_di(t_pf *pf)
{
  char	*str;
  int	nbr;

  nbr = va_arg(*pf->apx, int);
  str = my_getintnbr(nbr);
  if (pf->z_plus && nbr >= 0)
      str = my_strrecat(my_char_to_str('+'), str);
  return (str);
}

char	*flag_c(t_pf *pf)
{
  return (my_char_to_str((char) va_arg(pf->apx, int)));
}

char	*flag_s(t_pf *pf)
{
  char	*str;
  str = va_arg(pf->apx, char *);
  if (str == 0)
    return ("(null)");
  return (str);
}

char			*flag_p(t_pf *pf)
{
  char			*src;
  char			*str;
  long unsigned int	nbr;

  nbr = va_arg(*pf->apx, long unsigned int);
  if (nbr == 0)
    return ("(nil)");
  src = convert_base_lui_pf(nbr, "0123456789abcdef");
  if ((str = malloc((my_strlen(src) + 3) * sizeof(char))) == NULL)
    return (NULL);
  my_strcpy(str, "0x");
  my_strcat(str, src);
  return (str);
}
