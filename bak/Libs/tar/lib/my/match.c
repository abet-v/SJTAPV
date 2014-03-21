/*
** match.c for match-nmatch in /home/aslafy_z/rendu/Piscine-C-match-nmatch
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Sat Oct 12 12:56:52 2013 Zadkiel Aslafy Aharonian
** Last update Sun Dec  1 19:24:27 2013 Zadkiel Aslafy-Aharonian
*/

int     match(char *s1, char *s2)
{
  if (*s2 == '\0' && *s1 == '\0')
    return (1);
  if (*s2 == '*' && *(s2 + 1) != '\0' && *s1 == '\0')
    return (0);
  if (*s2 == '*' && *(s2 + 1) == '*')
    s2++;
  if (*s2 == *s1)
    return (match(s1 + 1, s2 + 1));
  if (*s2 == '*')
    return (match(s1, s2 + 1) || match(s1 + 1, s2));
  return (0);
}
