/*
** my_power_rec.c for day 05 in /home/aslafy_z/rendu/Piscine-C-Jour_05
** 
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
** 
** Started on  Fri Oct  4 09:19:43 2013 Zadkiel Aslafy Aharonian
** Last update Wed Oct  9 22:52:23 2013 Zadkiel Aslafy Aharonian
*/
int     my_power_rec(int nb, int power)
{
  if (power <= 0)
    return (1);
  return (nb * my_power_rec(nb, power - 1));
}
