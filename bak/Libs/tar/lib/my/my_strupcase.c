/*
** my_strupcase.c for day 06 in /home/aslafy_z/rendu/Piscine-C-Jour_06
** 
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
** 
** Started on  Mon Oct  7 09:50:01 2013 Zadkiel Aslafy Aharonian
** Last update Mon Oct  7 16:08:14 2013 Zadkiel Aslafy Aharonian
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	{
	  str[i] = 'A' + (str[i] - 'a');
	}
      i = i + 1;
    }
  return (str);
}
