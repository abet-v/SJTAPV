/*
** my_revstr.c for day 06 in /home/aslafy_z/rendu/Piscine-C-Jour_06
** 
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
** 
** Started on  Mon Oct  7 09:27:36 2013 Zadkiel Aslafy Aharonian
** Last update Mon Oct  7 17:58:28 2013 Zadkiel Aslafy Aharonian
*/

char	*my_revstr(char *str)
{
  int	i;
  int	len;
  int	temp;

  i = 0;
  len = 0;
  while (str[len] != '\0')
    {
      len = len + 1;
    }
  len = len - 1;
  while (i < len)
    {
      temp = str[len];
      str[len] = str[i];
      str[i] = temp;
      len = len - 1;
      i = i + 1;
    }
  return (str);
}
