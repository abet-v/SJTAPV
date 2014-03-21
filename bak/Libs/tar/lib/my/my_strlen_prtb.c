/*
** my_strlen_prtb.c for lib in /home/aslafy_z/rendu/PRINTF
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Sat Nov  2 21:26:41 2013 Zadkiel Aslafy Aharonian
** Last update Sun Nov 24 15:47:51 2013 Zadkiel Aslafy Aharonian
*/

int	my_strlen_prtb(char *str, int noprint_size)
{
  int	len;
  int	i;

  len = 0;
  i = 0;
  while (str && str[i])
    {
      len += (str[i] < 32 || str[i] >= 127) ? (noprint_size) : (1);
      i++;
    }
  return (len);
}
