/*
** my_isnum.c for lib in /home/aslafy_z/rendu/PSU_2013_my_printf
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Wed Nov 13 17:37:41 2013 Zadkiel Aslafy Aharonian
** Last update Wed Nov 13 17:37:45 2013 Zadkiel Aslafy Aharonian
*/

int	my_isnum(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}
