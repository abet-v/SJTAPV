/*
** my_strlen.c for day 04 in /home/aslafy_z/rendu/Piscine-C-Jour_04
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Thu Oct  3 09:11:16 2013 Zadkiel Aslafy Aharonian
** Last update Sun Nov 24 15:47:05 2013 Zadkiel Aslafy Aharonian
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
