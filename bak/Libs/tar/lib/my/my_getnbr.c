/*
** my_getnbr.c for day 04 in /home/aslafy_z/rendu/Piscine-C-Jour_04
** 
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
** 
** Started on  Thu Oct  3 09:58:39 2013 Zadkiel Aslafy Aharonian
** Last update Mon Oct 21 14:28:43 2013 Zadkiel Aslafy Aharonian
*/
long long	my_power_getnbr(int n, int pow)
{
  long long	result;

  result = 1;
  while (pow > 0)
    {
      result = result * n;
      pow = pow - 1;
    }
  return (result);
}

long long	my_getnbr_calc(char *str, int i, int neg)
{
  int		len;
  long long	result;
  long long	multi;

  result = 0;
  len = i;
  while (str[len] >= '0' && str[len] <= '9')
    {
      len = len + 1;
    }
  multi = my_power_getnbr(10, len - i - 1);
  while (i < len)
    {
      result = result + (str[i] - '0') * multi;
      multi = multi / 10;
      i = i + 1;
    }
  if (neg)
    result = result * -1;
  if (result > 2147483647 || result < -2147483648)
    {
      return (0);
    }
  return (result);
}

int	my_getnbr(char *str)
{
  int	i;
  int	neg;

  i = 0;
  neg = 0;
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
  return (my_getnbr_calc(str, i, neg));
}
