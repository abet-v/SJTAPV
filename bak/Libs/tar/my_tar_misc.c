/*
** my_tar.c for my_tar in /home/aslafy_z/rendu/PSU_2013_my_ls
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Fri Nov 29 16:49:46 2013 Zadkiel Aslafy Aharonian
** Last update Sun Dec  1 19:10:38 2013 Zadkiel Aslafy-Aharonian
*/

#include "my_tar.h"

char	*tar_get_path(char *old_path, char *file_name, int dir)
{
  char	*tmp;
  char	*path;

  if (old_path[strlen(old_path) - 1] == '/' && dir)
      path = my_strrecat(old_path, file_name);
  else if (old_path[strlen(old_path) - 1] != '/')
    {
      tmp = my_strrecat(old_path, "/");
      path = my_strrecat(tmp, file_name);
      free(tmp);
    }
  else
    path = my_strrecat(old_path, file_name);
  return (path);
}

int	tar_get_dir(char *path, struct dirent *rd, t_opt *opts)
{
  t_file	*file;

  if (!DOT_FILTER(rd->d_name))
    {
      file = tar_init_file();
      file->path = tar_get_path(path, rd->d_name, (rd->d_type == DT_DIR));
      CHECK_E(lstat(file->path, &file->stat), -1);
      make_header_and_archive(file, opts);
      if (S_ISDIR(file->stat.st_mode))
	tar_get(file->path, opts);
      tar_free_file(file);
    }
  return (0);
}

int	tar_get(char *path, t_opt *opts)
{
  DIR		*dd;
  struct dirent	*rd;
  struct stat	st;
  t_file	*file;

  CHECK(file = tar_init_file(opts), NULL, ERR_MALLOC);
  CHECK_E(lstat(path, &file->stat), -1);
  if (S_ISDIR(file->stat.st_mode))
    {
      CHECK_E(dd = opendir(path), NULL);
      file->path = strdup(path);
      make_header_and_archive(file, opts);
      while ((rd = readdir(dd)) != NULL)
	tar_get_dir(path, rd, opts);
      closedir(dd);
    }
  else
    {
      CHECK(file = tar_init_file(opts), NULL, ERR_MALLOC);
      CHECK_E(lstat(path, &file->stat), -1);
      file->path = strdup(path);
      make_header_and_archive(file, opts);
      tar_free_file(file);
    }
  return (0);
}
