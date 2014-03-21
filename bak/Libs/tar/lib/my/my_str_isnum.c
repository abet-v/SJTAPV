/*
** my_str_isnum.c for day 06 in /home/aslafy_z/rendu/Piscine-C-Jour_06
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Mon Oct  7 09:50:01 2013 Zadkiel Aslafy Aharonian
** Last update Mon Nov  4 23:25:26 2013 Zadkiel Aslafy Aharonian
*/

int	is_number(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (is_number(str[i]) || (str[i] == '-' && i == 0))
	i = i + 1;
      else
	return (0);
    }
  return (1);
}
