/*
** my_printf.c for lib in /home/aslafy_z/rendu/PSU_2013_my_printf
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Mon Nov 11 21:12:34 2013 Zadkiel Aslafy Aharonian
** Last update Sun Nov 24 15:13:33 2013 Zadkiel Aslafy Aharonian
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

void	pf_decal(va_list ap, t_pf *pf, const char *format, int *i)
{
  if (my_isnum(format[*i]))
    {
      if (format[*i] == '0' && pf->z_less == 0)
	{
	  pf->z_decalc = '0';
	  *i = *i + 1;
	}
      pf->z_longc = MY_ABS(my_getnbr(&format[*i]));
      while (my_isnum(format[*i]))
	*i = *i + 1;
    }
  else if (format[*i] == '*')
    {
      pf->z_longc = va_arg(ap, int);
      pf->z_longc = MY_ABS(pf->z_longc);
      *i = *i + 1;
      pf->z_decalc = ' ';
    }
}

t_pf		*pf_match(va_list ap, const char *format, int len, int *i)
{
  t_pf		*pf;
  ptr_flags	*ptr_flags;
  int		index;
  int		stop;

  stop = 0;
  pf = pf_init(len, i);
  pf->p_pos = *i - 1;
  ptr_flags = make_ptr_func();
  while (format[*i] && stop < 5)
    {
      pf_assign_first(ap, format, pf, i);
      stop++;
    }
  if ((index = my_strcpos(PF_FLAGS, format[*i])) > -1)
    {
      pf->fnct = ptr_flags[index];
      pf->flag = format[*i];
      pf->apx = ap;
    }
  if (index == -1)
    *i = pf->p_pos;
  if (index == -1)
    return (NULL);
  return (pf);
}

int	pf_get_str(t_pf *pf)
{
  int	len;
  char *str;
  char	tmp;

  str = pf->fnct(pf);
  len = my_strlen(str);
  if (pf_cond_spacing_one(pf))
    {
      tmp = (!my_instr("diouxX", pf->flag) ? ' ' : pf->z_decalc);
      len += pf_print(my_makecstr(tmp, pf->z_longc - len));
    }
  if (pf_cond_spacing_char(pf))
    my_putchar(' ');
  my_putstr(str);
  if (pf_cond_spacing_two(pf))
    len += pf_print(my_makecstr(' ', pf->z_longc - len));
  free(pf);
  return (len);
}

int		my_printf(const char *format, ...)
{
  va_list	ap;
  t_pf		*pf;
  char		*str;
  int		len;
  int		i;

  i = 0;
  len = 0;
  va_start(ap, format);
  while (format && format[i])
    {
      if (format[i] == '%'
	  && (pf = pf_match(ap, format, len, &i)) != NULL)
	{
	  len += pf_get_str(pf);
	}
      else
	{
	  my_putchar(format[i]);
	  len++;
	}
      i++;
    }
  va_end(ap);
  return (len);
}
