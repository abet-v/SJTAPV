/*
** my_str_isalpha.c for day 06 in /home/aslafy_z/rendu/Piscine-C-Jour_06
** 
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
** 
** Started on  Mon Oct  7 09:50:01 2013 Zadkiel Aslafy Aharonian
** Last update Mon Oct  7 16:13:35 2013 Zadkiel Aslafy Aharonian
*/

int	is_alphabetic(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
  return (0);
}

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!is_alphabetic(str[i]))
	{
	  return (0);
	}
      i = i + 1;
    }
  return (1);
}
