/*
** my_printf_flags3.c for my_printf in /home/aslafy_z/rendu/CPE_2013_getnextline
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Sun Nov 24 15:10:20 2013 Zadkiel Aslafy Aharonian
** Last update Sun Nov 24 15:10:54 2013 Zadkiel Aslafy Aharonian
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#define  __MY_PRINTF_FLAGS__
#include "my_printf.h"

char	*flag_u(t_pf *pf)
{
  return (my_getuintnbr(va_arg(*pf->apx, unsigned int)));
}

char	*flag_n(t_pf *pf)
{
  int	*param;

  param = va_arg(*pf->apx, int *);
  *param = pf->the_len;
  return ("");
}
