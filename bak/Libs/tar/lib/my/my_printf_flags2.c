/*
** my_printf_flags2.c for my_printf in /home/aslafy_z/rendu/CPE_2013_getnextline
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Sun Nov 24 15:09:27 2013 Zadkiel Aslafy Aharonian
** Last update Sun Nov 24 15:16:31 2013 Zadkiel Aslafy Aharonian
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#define  __MY_PRINTF_FLAGS__
#include "my_printf.h"

char	*flag_b(t_pf *pf)
{
  char	*s;

  s = convert_base_lui_pf(va_arg(*pf->apx, unsigned int), "01");
  if (pf->z_sharp && my_strcmp(s, "0") != 0)
    return (my_strrecat("b" , s));
  return (s);
}

char	*flag_x(t_pf *pf)
{
  char	*s;

  s = convert_base_lui_pf(va_arg(*pf->apx, unsigned int), "0123456789abcdef");
  if (pf->z_sharp && my_strcmp(s, "0") != 0)
    return (my_strrecat("0x" , s));
  return (s);
}

char	*flag_X(t_pf *pf)
{
  char	*s;

  s = convert_base_lui_pf(va_arg(*pf->apx, unsigned int), "0123456789ABCDEF");
  if (pf->z_sharp && my_strcmp(s, "0") != 0)
    return (my_strrecat("0X" , s));
  return (s);
}

char	*flag_o(t_pf *pf)
{
  char	*s;

  s = convert_base_lui_pf(va_arg(*pf->apx, unsigned int), "01234567");
  if (pf->z_sharp && my_strcmp(s, "0") != 0)
    return (my_strrecat("0" , s));
  return (s);
}

char	*flag_S(t_pf *pf)
{
  char	*str;
  char	*result;
  char	*tmp;
  int	i;
  int	len;

  str = va_arg(*pf->apx, char *);
  if (str == 0)
    return ("(null)");
  if ((result = malloc((my_strlen_prtb(str, 4) + 1) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (str && str[i])
    {
      if (str[i] < 32 || str[i] >= 127)
	{
	  my_strccat(result, '\\');
	  tmp = convert_base_int_pf((int) str[i++], "01234567");
	  my_strcat(result, my_complete_str(tmp, '0', 3));
	}
      else
	my_strccat(result, str[i++]);
    }
  result[my_strlen_prtb(str, 4)] = 0;
  return (result);
}
