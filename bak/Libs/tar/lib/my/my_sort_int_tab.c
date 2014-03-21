/*
** my_sort_int_tab.c for day 04 in /home/aslafy_z/rendu/Piscine-C-Jour_04
** 
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
** 
** Started on  Thu Oct  3 14:54:32 2013 Zadkiel Aslafy Aharonian
** Last update Fri Oct  4 23:42:26 2013 Zadkiel Aslafy Aharonian
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	error;
  int	i;
  int	tmp;

  i = 0;
  error = 0;
  while (i < size -1)
    {
      if (tab[i + 1] < tab[i])
	{
	  tmp = tab[i];
	  tab[i] = tab[i + 1];
	  tab[i + 1] = tmp;
	  error = 1;
	}
      if (i == size - 2 && error == 1)
	{
	  i = -1;
	  error = 0;
	}
      i = i + 1;
    }
}
