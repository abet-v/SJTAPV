/*
** my_strlowcase.c for day 06 in /home/aslafy_z/rendu/Piscine-C-Jour_06
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Mon Oct  7 09:50:01 2013 Zadkiel Aslafy Aharonian
** Last update Sun Nov 24 15:46:10 2013 Zadkiel Aslafy Aharonian
*/

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	  str[i] = 'a' + (str[i] - 'A');
      i++;
    }
  return (str);
}
