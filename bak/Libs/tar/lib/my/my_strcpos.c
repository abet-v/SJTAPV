/*
** my_strcpos.c for bistromathique in /home/aslafy_z/rendu/Bistro/srcs
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Sat Nov  9 14:41:34 2013 Zadkiel Aslafy Aharonian
** Last update Sat Nov  9 14:41:41 2013 Zadkiel Aslafy Aharonian
*/

int	my_strcpos(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	return (i);
      i = i + 1;
    }
  return (-1);
}
