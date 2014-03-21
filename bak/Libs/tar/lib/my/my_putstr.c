/*
** my_putstr.c for day 04 in /home/aslafy_z/rendu/Piscine-C-Jour_04
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Thu Oct  3 09:09:46 2013 Zadkiel Aslafy Aharonian
** Last update Fri Nov 22 06:54:31 2013 Zadkiel Aslafy Aharonian
*/
int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  write(1, str, i);
}
