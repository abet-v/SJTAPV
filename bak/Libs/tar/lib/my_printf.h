/*
** my_printf.h for my_printf in /home/aslafy_z/rendu/PSU_2013_my_printf
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Mon Nov 11 23:27:57 2013 Zadkiel Aslafy Aharonian
** Last update Fri Nov 22 23:46:25 2013 Zadkiel Aslafy Aharonian
*/

#ifndef __MY_PRINTF_ALL__
#define __MY_PRINTF_ALL__

#include <stdarg.h>
#define PF_FLAGS	"%dicspoxbXSun "

typedef struct s_pf
{
  va_list	*apx;
  int		p_pos;
  int		z_plus;
  int		z_less;
  int		z_space;
  int		z_sharp;
  int		z_zero;
  int		z_precis;
  int		z_longc;
  char		z_decalc;
  char		flag;
  int		the_len;
  char		*(*fnct)(struct s_pf *pf);
} t_pf;

typedef char *(*ptr_flags)(t_pf *pf);

#endif

#ifndef __MY_PRINTF__
#define __MY_PRINTF__

int	my_printf(const char *format, ...);
char	*convert_base_lui_pf(long unsigned int nbr, char *base_to);
char	*convert_base_int_pf(int nbr, char *base_to);
char    *convert_base_str_pf(char *nbr, char *base_from, char *base_to);
void	pf_assign_first(va_list ap, const char *format, t_pf *pf, int *i);
void	pf_assign_second(va_list ap, const char *format, t_pf *pf, int *i);
int	pf_cond_spacing_one(t_pf *pf);
int	pf_cond_spacing_two(t_pf *pf);
int	pf_cond_spacing_char(t_pf *pf);
int	pf_print(char *str);
t_pf	*pf_init(int len, int *i);
ptr_flags	*make_ptr_func();

#endif

#ifndef __MY_PRINTF_FLAGS__
#define __MY_PRINTF_FLAGS__

char	*flag_perc(t_pf *);
char	*flag_di(t_pf *);
char	*flag_c(t_pf *);
char	*flag_s(t_pf *);
char	*flag_p(t_pf *);
char	*flag_b(t_pf *);
char	*flag_x(t_pf *);
char	*flag_X(t_pf *);
char	*flag_o(t_pf *);
char	*flag_S(t_pf *);
char	*flag_u(t_pf *);
char	*flag_n(t_pf *);

#endif
