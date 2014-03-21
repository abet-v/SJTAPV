/*
** my_strlcat.c for day 07 in /home/aslafy_z/rendu/Piscine-C-Jour_07/ex_01
** 
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
** 
** Started on  Tue Oct  8 09:53:29 2013 Zadkiel Aslafy Aharonian
** Last update Tue Oct  8 16:03:15 2013 Zadkiel Aslafy Aharonian
*/

int	my_strlcat(char *dest, char *src, int size)
{
  int	i;
  int	dest_len;
  int	src_len;

  i = 0;
  dest_len = my_strlen(dest);
  src_len = my_strlen(src);
  if (dest_len < size)
    {
      size = dest_len;
    }
  while (src[i] != '\0')
    {
      dest[size + i] = src[i];
      i = i + 1;
    }
  dest[size + i] = '\0';
  return (my_strlen(dest));
}
