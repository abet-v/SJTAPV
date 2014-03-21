/*
** my_memset.c for lib in /home/aslafy_z/epitech/Lib/my
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Sat Nov 23 15:44:42 2013 Zadkiel Aslafy Aharonian
** Last update Tue Nov 26 15:21:25 2013 Zadkiel Aslafy Aharonian
*/

void	my_memset(char *s, char c, int n)
{
  int	i;

  i = 0;
  while (i < n)
    s[i++] = c;
}
