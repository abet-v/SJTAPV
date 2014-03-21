/*
** my_getnbr_base.c for libmy in /home/aslafy_z/rendu/Piscine-C-Jour_06
** 
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
** 
** Started on  Wed Oct  9 09:56:01 2013 Zadkiel Aslafy Aharonian
** Last update Thu Oct 10 23:14:56 2013 Zadkiel Aslafy Aharonian
*/

int	my_charstr_base(char *src, char to_find)
{
  int	i;
  int	result;

  i = 0;
  result = 0;
  while (src[i])
    {
      if (src[i] == to_find)
	result = result + 1;
      i = i + 1;
    }
  if (result != 1)
    return (0);
  return (1);
}

int	my_getposin_base(char *src, char to_find)
{
  int	i;

  i = 0;
  while (src[i])
    {
      if (src[i] == to_find)
	return (i);
      i = i + 1;
    }
  return (0);
}

int	my_getnbr_base_calc(char *str, int i, int neg, char *base)
{
  int	result;
  int	len;
  int	pos;
  int	j;

  len = 0;
  result = 0;
  j = 0;
  while (str[i + len] != '\0')
    {
      if (!my_charstr_base(base, str[i + len]))
	return (0);
      len = len + 1;
    }
  len = len - 1;
  while (len >= 0)
    {
      pos = my_getposin_base(base, str[i + j]);
      result = result + (pos * my_power_rec(my_strlen(base), len));
      j = j + 1;
      len = len - 1;
    }
  if (neg)
    result = -result;
  return (result);
}

int	my_getnbr_base(char *str, char *base)
{
  int	i;
  int	neg;

  i = 0;
  neg = 0;
  if (my_strlen(str) == 0 || my_strlen(base) == 0)
    return (0);
  while (str[i] == '+' || str[i] == '-')
    {
      if (str[i] == '-')
	{
	  if (neg == 0)
	    {
	      neg = 1;
	    }
	  else
	    {
	      neg = 0;
	    }
	}
      i = i + 1;
    }
  return (my_getnbr_base_calc(str, i, neg, base));
}
