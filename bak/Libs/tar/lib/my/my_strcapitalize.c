/*
** my_strcapitalize.c for day 06 in /home/aslafy_z/rendu/Piscine-C-Jour_06
** 
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
** 
** Started on  Mon Oct  7 09:50:01 2013 Zadkiel Aslafy Aharonian
** Last update Mon Oct  7 16:12:17 2013 Zadkiel Aslafy Aharonian
*/

int	is_alpha(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
  else if (c >= '0' && c <= '9')
    return (1);
  else
    return (0);
}

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (i == 0 || !is_alpha(str[i - 1]) || str[i - 1] == ' ')
	{
	  if (str[i] >= 'a' && str[i] <= 'z')
	    {
	      str[i] = 'A' + (str[i] - 'a');
	    }
	}
      i = i + 1;
    }
  return (str);
}
