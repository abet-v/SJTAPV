/*
** my_strncpy.c for day 06 in /home/aslafy_z/rendu/Piscine-C-Jour_06
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Mon Oct  7 09:23:45 2013 Zadkiel Aslafy Aharonian
** Last update Wed Nov 20 18:26:29 2013 Zadkiel Aslafy Aharonian
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
