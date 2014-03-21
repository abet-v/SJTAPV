/*
** my_strstr.c for day 06 in /home/aslafy_z/rendu/Piscine-C-Jour_06
** 
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
** 
** Started on  Mon Oct  7 09:50:01 2013 Zadkiel Aslafy Aharonian
** Last update Tue Oct  8 14:37:11 2013 Zadkiel Aslafy Aharonian
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0)
    {
      i = i + 1;
    }

  return (s1[i] - s2[i]);
}
