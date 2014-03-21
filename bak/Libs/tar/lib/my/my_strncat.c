/*
** my_strncat.c for day 07 in /home/aslafy_z/rendu/Piscine-C-Jour_07/ex_01
** 
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
** 
** Started on  Tue Oct  8 09:53:29 2013 Zadkiel Aslafy Aharonian
** Last update Tue Oct  8 15:42:34 2013 Zadkiel Aslafy Aharonian
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	dest_len;

  i = 0;
  dest_len = my_strlen(dest);
  while (src[i] != '\0' && i < nb)
    {
      dest[dest_len] = src[i];
      dest_len = dest_len + 1;
      i = i + 1;
    }
  dest[dest_len] = '\0';
  return (dest);
}