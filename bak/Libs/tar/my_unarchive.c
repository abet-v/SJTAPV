/*
** my_archive.c for my_archive in /home/aslafy_z/rendu/PSU_2013_my_ls
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Sat Nov 30 20:45:30 2013 Zadkiel Aslafy Aharonian
** Last update Sun Dec  1 18:52:27 2013 Zadkiel Aslafy-Aharonian
*/

#include "my_tar.h"

int	write_to_file(FILE *fd_in, t_header *head)
{
  FILE	*fd_out;
  int	tmp;
  int	i;
  char	buffer[512];

  i = 0;
  CHECK_E(fd_out = fopen(head->path, "w"), NULL);
  while (i < (head->size / 512))
    {
      fread(buffer, 512, 1, fd_in);
      fwrite(buffer, 512, 1, fd_out);
      i++;
    }
  tmp = head->size % 512;
  if (tmp)
    {
      fread(&buffer, tmp, 1, fd_in);
      fwrite(&buffer, tmp, 1, fd_out);
      fseek(fd_in, (512 - tmp), SEEK_CUR);
    }
  fclose(fd_out);
  return (0);
}

int			set_time(char *path, time_t time)
{
  struct utimbuf	tim;

  tim.modtime = time;
  tim.actime = time;
  utime(path, &tim);
  return (0);
}

t_header	*get_header(char *header)
{
  t_header	*head;

  CHECK_V(head = tar_init_head(NULL), NULL, NULL);
  head->path = strndup(&header[0], 99);
  head->mode = atoi(strndup(&header[100], 7));
  head->uid = OCT2DEC(strndup(&header[108], 7));
  head->gid = OCT2DEC(strndup(&header[116], 7));
  head->size = OCT2DEC(strndup(&header[124], 11));
  head->time = (time_t) OCT2DEC(strndup(&header[136], 11));
  head->cksum = OCT2DEC(strndup(&header[148], 7));
  head->type = (int) (strndup(&header[156], 1)[0] - '0');
  return (head);
}

int	lsekk(FILE *fd_in, char *header)
{
  if (match(strndup(&header[0], 99), "*PaxHeaders*"))
    {
      fseek(fd_in, 512, SEEK_CUR);
      fread(&header[0], 512, 1, fd_in);
    }
  else if (get_control_sum(&header[0]) == 0)
    {
      return (0);
    }
  return (1);
}

int		parse_header_and_create(t_opt *opts)
{
  FILE		*fd_in;
  char		header[512];
  t_header	*head;

  CHECK_E(fd_in = fopen(opts->out, "r"), NULL);
  while (fread(&header, 512, 1, fd_in) && lsekk(fd_in, &header[0]))
    {
      CHECK(head = get_header(&header[0]), NULL, ERR_MALLOC);
      (opts->is['v']) ? printf("%s\n", head->path) : 1;
      if (head->type == 0)
	{
	  write_to_file(fd_in, head);
	  chmod(head->path,  itomode((opts->is['p']) ? (head->mode) : (755)));
	  set_time(head->path, head->time);
	}
      else if (head->type == 5)
	{
	  mkdir(head->path, 755);
	  chmod(head->path, itomode((opts->is['p']) ? (head->mode) : (755)));
	  set_time(head->path, head->time);
	}
    }
  tar_init_head(head);
  return (0);
}
