/*
** my_archive.c for my_archive in /home/aslafy_z/rendu/PSU_2013_my_ls
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Sat Nov 30 20:45:30 2013 Zadkiel Aslafy Aharonian
** Last update Sun Dec  1 18:34:45 2013 Zadkiel Aslafy-Aharonian
*/

#include "my_tar.h"

int	write_archive(FILE *fd_out, t_file *file)
{
  FILE	*fd_in;
  int	tmp;
  int	i;
  char	buffer[512];

  i = 0;
  if (!S_ISDIR(file->stat.st_mode))
    {
      CHECK_E(fd_in = fopen(file->path, "r"), NULL);
      while (i < (file->stat.st_size / 512))
	{
	  fread(&buffer, 512, 1, fd_in);
	  fwrite(&buffer, 512, 1, fd_out);
	  i++;
	}
      tmp = file->stat.st_size % 512;
      if (tmp)
	{
	  fread(&buffer, tmp, 1, fd_in);
	  fwrite(&buffer, tmp, 1, fd_out);
	  fwrite(memset(&buffer, 0, (512 - tmp)), (512 - tmp), 1, fd_out);
	}
      fclose(fd_in);
    }
  return (0);
}

int	make_header_and_archive(t_file *file, t_opt *opts)
{
  FILE	*fd_out;
  char	*header;

  CHECK_E(fd_out = fopen(opts->out, "a"), NULL);
  CHECK(header = calloc(1, 512), NULL, ERR_MALLOC);
  (opts->is['v']) ? printf("%s\n", file->path) : 1;
  strncpy(&header[0], file->path, 100);
  sprintf(&header[100], "%07o", get_file_mode(file->stat.st_mode));
  sprintf(&header[108], "%07o", file->stat.st_uid);
  sprintf(&header[116], "%07o", file->stat.st_gid);
  sprintf(&header[124], get_file_size(file), file->stat.st_size);
  sprintf(&header[136], "%011o", file->stat.st_mtime);
  sprintf(&header[148], "       ");
  sprintf(&header[155], " %c", get_file_type(file->stat.st_mode));
  sprintf(&header[257], "ustar");
  sprintf(&header[263], "00");
  sprintf(&header[265], "%s", getpwuid(file->stat.st_uid)->pw_name);
  sprintf(&header[297], "%s", getgrgid(file->stat.st_gid)->gr_name);
  sprintf(&header[329], "%07o", major(file->stat.st_dev));
  sprintf(&header[337], "%07o", minor(file->stat.st_dev));
  sprintf(&header[148], "%06o", get_control_sum(header));
  fwrite(header, 512, 1, fd_out);
  write_archive(fd_out, file);
  fclose(fd_out);
  return (0);
}
