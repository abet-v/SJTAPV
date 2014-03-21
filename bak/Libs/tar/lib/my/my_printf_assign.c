/*
** my_printf_assign.c for my_printf in /home/aslafy_z/rendu/PSU_2013_my_printf
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Sun Nov 17 21:46:20 2013 Zadkiel Aslafy Aharonian
** Last update Sun Nov 17 22:47:25 2013 Zadkiel Aslafy Aharonian
*/

#include <stdarg.h>
#include "my.h"
#include "my_printf.h"

void	pf_assign_first(va_list ap, const char *format, t_pf *pf, int *i)
{
  if (format[*i] == '#')
    {
      pf->z_sharp = 1;
      *i = *i + 1;
    }
  if (format[*i] == '-')
    {
      pf->z_less = 1;
      *i = *i + 1;
    }
  if (format[*i] == '+')
    {
      pf->z_plus = 1;
      *i = *i + 1;
    }
  if (format[*i] == '.')
    {
      pf->z_precis = 1;
      *i = *i + 1;
      while (my_isnum(format[*i]))
	*i = *i + 1;
    }
  pf_assign_second(ap, format, pf, i);
}

void	pf_assign_second(va_list ap, const char *format, t_pf *pf, int *i)
{
  if (format[*i] == ' ')
    {
      pf->z_space = 1;
      while (format[*i] == ' ')
	*i = *i + 1;
    }
  if (format[*i] == 'l')
    {
      *i = *i + 1;
    }
  pf_decal(ap, pf, format, i);
}

int	pf_cond_spacing_one(t_pf *pf)
{
  if (pf->z_longc > 0 && pf->z_decalc
    && !pf->z_less && pf->flag != '%')
    return (1);
  return (0);
}

int	pf_cond_spacing_two(t_pf *pf)
{
  if (pf->z_longc > 0 && pf->z_decalc
      && pf->z_less && pf->flag != '%')
    return (1);
  return (0);
}

int	pf_cond_spacing_char(t_pf *pf)
{
  if (pf->z_space && (!pf->z_longc || pf->z_less)
      && my_instr("dp", pf->flag) && !pf->z_plus)
    {
      if (pf->z_longc)
	pf->z_longc--;
      return (1);
    }
  return (0);
}
