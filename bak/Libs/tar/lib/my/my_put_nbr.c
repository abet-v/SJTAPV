/*
** my_put_nbr.c for day 03 in /home/aslafy_z/rendu/Piscine-C-Jour_03
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Wed Oct  2 11:19:22 2013 Zadkiel Aslafy Aharonian
** Last update Wed Nov 13 20:33:31 2013 Zadkiel Aslafy Aharonian
*/

int	my_put_nbr(int nb)
{
  long long	n;

  n = nb;
  if (n < 0)
    {
      my_putchar('-');
      n = -n;
    }
  if (n < 10)
    {
      my_putchar('0' + n);
      return (0);
    }
  my_put_nbr(n / 10);
  my_putchar('0' + n % 10);
  return (0);
}
