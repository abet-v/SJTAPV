/*
** my_str_to_worldtab.c for day 09 in /home/aslafy_z/rendu/Piscine-C-Jour_08/ex_04
** 
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
** 
** Started on  Thu Oct 10 17:16:38 2013 Zadkiel Aslafy Aharonian
** Last update Fri Oct 11 20:38:35 2013 Zadkiel Aslafy Aharonian
*/

#include <stdlib.h>
char    *my_strdup(char *src);

int	my_str_is_alphanum(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
  else if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int	my_str_count_word(char *s)
{
  int   i;
  int   cpt;

  i = 0;
  cpt = 0;
  while (s[i])
    {
      if (my_str_is_alphanum(s[i]))
        {
          cpt = cpt + 1;
          while (s[i] && my_str_is_alphanum(s[i]))
            i = i + 1;
        }
      i = i + 1;
    }
  return (cpt);
}

int	my_str_count_char(char *s, int *i)
{
  int   cpt;

  cpt = 0;
  while (s[*i] && my_str_is_alphanum(s[*i]))
    {
      cpt = cpt + 1;
      *i = *i + 1;
    }
  return (cpt);
}

char    **my_str_to_wordtab(char *str)
{
  int   i;
  int   j;
  int   word;
  char  **tab;

  i = 0;
  j = 0;
  word = my_str_count_word(my_strdup(str));
  tab = malloc(word * sizeof(char *) + 1);
  while (str[i] && word > 0)
    {
      if (my_str_is_alphanum(str[i]))
        {
	  tab[j] = my_strdup(str + i);
	  tab[j][my_str_count_char(str, &i)] = '\0';
	  j = j + 1;
          word = word - 1;
        }
      i = i + 1;
    }
  tab[my_str_count_word(str)] = '\0';
  return (tab);
}
