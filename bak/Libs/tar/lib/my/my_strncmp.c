/*
** my_strncmp.c for day 06 in /home/aslafy_z/rendu/Piscine-C-Jour_06
** 
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
** 
** Started on  Mon Oct  7 09:50:01 2013 Zadkiel Aslafy Aharonian
** Last update Mon Oct 21 20:43:55 2013 Zadkiel Aslafy Aharonian
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (i < n && s1[i] == s2[i] && s1[i] && s2[i])
    i = i + 1;
  if (s1[i] != s2[i] && i != n)
    return (s1[i] - s2[i]);
  return (0);
}
