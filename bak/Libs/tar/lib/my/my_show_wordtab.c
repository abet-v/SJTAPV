/*
** my_show_wordtab.c for day 09 in /home/aslafy_z/rendu/Piscine-C-Jour_08/ex_04
** 
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
** 
** Started on  Thu Oct 10 17:54:21 2013 Zadkiel Aslafy Aharonian
** Last update Fri Oct 11 20:19:38 2013 Zadkiel Aslafy Aharonian
*/

int	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
  return (0);
}
