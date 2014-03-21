/*
** my_swap.c for day 04 in /home/aslafy_z/rendu/Piscine-C-Jour_04
** 
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
** 
** Started on  Thu Oct  3 09:02:42 2013 Zadkiel Aslafy Aharonian
** Last update Fri Oct  4 23:40:40 2013 Zadkiel Aslafy Aharonian
*/
int	my_swap(int *a, int *b)
{
  int	temp;

  temp = *b;
  *b = *a;
  *a = temp;
}
