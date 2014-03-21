/*
** my_tar_init.c for my_ls in /home/aslafy_z/rendu/PSU_2013_my_ls
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Sun Nov 24 17:41:50 2013 Zadkiel Aslafy Aharonian
** Last update Sun Dec  1 09:50:25 2013 Zadkiel Aslafy-Aharonian
*/

#include "my_tar.h"

t_file		*tar_init_file()
{
  t_file	*file;

  CHECK_V(file = malloc(sizeof(t_file)), NULL, NULL);
  file->path = NULL;
  return (file);
}

t_header	*tar_init_head(t_header *header)
{
  t_header	*head;

  if (!header)
    {
      CHECK_V(head = malloc(sizeof(t_header)), NULL, NULL);
      head->path = NULL;
      head->mode = 0;
      head->uid = 0;
      head->gid = 0;
      head->size = 0;
      head->cksum = 0;
      head->time = 0;
      head->type = 0;
      return (head);
    }
  else
    {
      free(header->path);
      free(header);
    }
}

t_opt	*tar_init_opt()
{
  t_opt	*opts;
  int	i;

  i = 0;
  CHECK_V(opts = malloc(sizeof(t_opt)), NULL, NULL);
  while (i < 255)
    opts->is[i++] = 0;
  opts->folders = NULL;
  opts->out = NULL;
  opts->a_cnt = 0;
  opts->f_cnt = 0;
  return (opts);
}

void	tar_free_file(t_file *file)
{
  free(file->path);
  free(file);
}

void	tar_free_opt(t_opt *opts)
{
  int	i;

  i = -1;
  while (opts->folders[++i] != NULL)
    free(opts->folders[i]);
  free(opts->folders);
  free(opts->is);
  free(opts);
}
