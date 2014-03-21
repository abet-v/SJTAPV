/*
** my_putnbr_base.c for day 06 in /home/aslafy_z/rendu/Piscine-C-Jour_06
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Mon Oct  7 18:00:47 2013 Zadkiel Aslafy Aharonian
** Last update Tue Oct 29 17:16:59 2013 Zadkiel Aslafy Aharonian
*/

int	my_putnbr_base(int nbr, char *base)
{
  int	modulo;
  int	divide;
  int	base_size;

  if (nbr < 0)
    {
      nbr = -nbr;
      my_putchar('-');
    }
  base_size = my_strlen(base);
  modulo = nbr % base_size;
  if (nbr >= base_size)
    {
      my_putchar(base[modulo]);
      my_putnbr_base(nbr / base_size, base);
    }
  else
    {
      my_putchar(base[modulo]);
    }
  return (nbr);
}
