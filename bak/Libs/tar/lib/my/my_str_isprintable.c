/*
** my_str_isprintable.c for day 06 in /home/aslafy_z/rendu/Piscine-C-Jour_06
** 
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
** 
** Started on  Mon Oct  7 09:50:01 2013 Zadkiel Aslafy Aharonian
** Last update Mon Oct  7 16:15:23 2013 Zadkiel Aslafy Aharonian
*/

int	my_str_isprintable(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127)
	{
	  return (0);
	}
      i = i + 1;
    }
  return (1);
}
