/*
** my_tar_get.c for my_tar in /home/aslafy_z/rendu/rush_my_tar/etape_2
**
** Made by Zadkiel Aslafy-Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Sun Dec  1 05:22:31 2013 Zadkiel Aslafy-Aharonian
** Last update Sun Dec  1 05:24:11 2013 Zadkiel Aslafy-Aharonian
*/

#include "my_tar.h"

char	get_file_type(mode_t m)
{
  char	type;

  type = '0';
  if (S_ISBLK(m) && type == '0')
    type = '4';
  if (S_ISCHR(m) && type == '0')
    type = '3';
  if (S_ISDIR(m) && type == '0')
    type = '5';
  if (S_ISFIFO(m) && type == '0')
    type = '6';
  if (S_ISLNK(m) && type == '0')
    type = '2';
  if (S_ISREG(m) && type == '0')
    type = '0';
  return (type);
}

int	get_file_mode(mode_t m)
{
  return ((m & S_IRWXU) + (m & S_IRWXG) + (m & S_IRWXO));
}

int	get_control_sum(char *header)
{
  int	i;
  int	c;

  i = 0;
  c = 0;
  while (i < 512)
    c += header[i++];
  return (c);
}

char	*get_file_size(t_file *file)
{
  if (!S_ISDIR(file->stat.st_mode))
    return ("%011llo");
  else
    return ("00000000000");
}
