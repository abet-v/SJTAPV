/*
** my.h for lib in /home/aslafy_z/rendu/Piscine-C-include
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Thu Oct 10 11:38:02 2013 Zadkiel Aslafy Aharonian
** Last update Sun Dec  1 19:29:56 2013 Zadkiel Aslafy-Aharonian
*/

#ifndef __MY_H_DEF
#define __MY_H_DEF

#include "my_printf.h"
#define	MY_ABS(a)	((a) < 0 ? -(a) : (a))
#define MY_LEFT		1
#define MY_RIGHT	2

typedef long unsigned int	t_lui;

int	my_printf(const char *format, ...);
char	*my_alignstr(char *str, char c, int max, int direction);
int	my_memset(char *s, char c, int n);
int	my_atoi(char *str);
int	match(char *s1, char *s2);
int	my_isnum(char c);
int	my_nbrlen(int nbr);
char	*my_complete_str(char *str, char c, int n);
char	*my_char_to_str(char c);
char	*my_strccat(char *dest, char c);
char	*my_trimstr(char *str, char c, int direction);
char	*my_getintnbr(int n);
char	*my_getuintnbr(unsigned int n);
int	my_strcpos(char *str, char c);
char	*my_strrecat(char *str1, char *str2);
char	*my_strcut(char *str, int cut);
char	*my_getuintnbr(unsigned int nbr);
int	my_find_prime_sup(int nb);
char	*my_makecstr(char c, int n);
int	my_getnbr(const char *str);
int	my_getnbr_base(char *str, char *base);
int	my_isneg(int n);
char	*my_str_getpos(char *str, int pos1, int pos2);
int	my_is_prime(int nombre);
int	my_putchar(char c);
int	my_strlen_prtb(char *str, int noprint_size);
int	my_instr(char *str, char c);
int	my_putnbr_base(int nbr, char *base);
char	*my_putgetnbr_base(int nbr, char *base);
int	my_put_nbr(int nb);
int	my_putstr(char *str);
char	*my_revstr(char *str);
int	my_showmem(char *str, int size);
int	my_showstr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_square_root(int nb);
int	is_alpha(char c);
char	*my_strcapitalize(char *str);
char	*my_strcat(char *dest, char *src);
int	my_strcmp(char *s1, char *s2);
char	*my_strcpy(char *dest, char *src);
int	my_str_isalpha(char *str);
int	my_str_islower(char *str);
int	my_str_isnum(char *str);
int	my_str_isprintable(char *str);
int	my_str_isupper(char *str);
int	my_strlcat(char *dest, char *src, int size);
int	my_strlen(char *str);
char	*my_strlowcase(char *str);
char	*my_strncat(char *dest, char *src, int nb);
char	*my_strrecat(char *str1, char *str2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_strstr(char *str, char *to_find);
char	*my_strupcase(char *str);
int	my_swap(int *a, int *b);
char	*my_strdup(char *str);
char    *my_str_replace(char *search, char *replace, char *str);
char	*my_putnbr_convert_base(int nbr, char *base, char *str, int i);
char	*my_putnbr_convert_base_m(int nbr, char *base);
char	*convert_base(char *nbr, char *base_from, char *base_to);

#endif
