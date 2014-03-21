/*
** my_printf_init.c for my_printf in /home/aslafy_z/rendu/PSU_2013_my_printf
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Sun Nov 17 23:19:52 2013 Zadkiel Aslafy Aharonian
** Last update Sun Nov 17 23:27:11 2013 Zadkiel Aslafy Aharonian
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"
#include "my_printf.h"

int	pf_print(char *str)
{
  int	len;

  my_putstr(str);
  len = my_strlen(str);
  free(str);
  return (len);
}

t_pf	*pf_init(int len, int *i)
{
  t_pf	*pf;

  if ((pf = malloc(sizeof(t_pf))) == NULL)
    return (NULL);
  pf->apx = NULL;
  pf->the_len = len;
  pf->z_plus = 0;
  pf->z_less = 0;
  pf->z_space = 0;
  pf->z_sharp = 0;
  pf->z_zero = 0;
  pf->z_precis = 0;
  pf->z_longc = 0;
  pf->z_decalc = ' ';
  pf->flag = 0;
  pf->fnct = NULL;
  *i = *i + 1;
  return (pf);
}

ptr_flags	*make_ptr_func()
{
  ptr_flags	*ptr_flag;

  ptr_flag = malloc(sizeof(ptr_flag) * 15);
  ptr_flag[0] = &flag_perc;
  ptr_flag[1] = &flag_di;
  ptr_flag[2] = &flag_di;
  ptr_flag[3] = &flag_c;
  ptr_flag[4] = &flag_s;
  ptr_flag[5] = &flag_p;
  ptr_flag[6] = &flag_o;
  ptr_flag[7] = &flag_x;
  ptr_flag[8] = &flag_b;
  ptr_flag[9] = &flag_X;
  ptr_flag[10] = &flag_S;
  ptr_flag[11] = &flag_u;
  ptr_flag[12] = &flag_n;
  ptr_flag[13] = 0;
  return (ptr_flag);
}
