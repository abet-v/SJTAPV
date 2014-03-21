/*
** my_isneg.c for day 03 in /home/aslafy_z/rendu/Piscine-C-Jour_03
** 
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
** 
** Started on  Wed Oct  2 09:45:34 2013 Zadkiel Aslafy Aharonian
** Last update Wed Oct  2 14:37:20 2013 Zadkiel Aslafy Aharonian
*/
int	my_isneg(int n)
{
  if (n >= 0)
    {
      my_putchar('P');
    }
  else
    {
      my_putchar('N');
    }
  return (0);
}
