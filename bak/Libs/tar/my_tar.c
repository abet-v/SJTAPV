/*
** my_tar.c for my_tar i /home/aslafy_z/rendu/PSU_2013_my_tar
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Fri Nov 22 18:09:57 2013 Zadkiel Aslafy Aharonian
** Last update Sun Dec  1 19:19:52 2013 Zadkiel Aslafy-Aharonian
*/

#include "my_tar.h"

void	tar_options_spec(t_opt *opts, char **argv, int *i)
{
  int	j;

  j = 1;
  while (argv[*i][j] != '\0')
    {
      opts->is[(size_t) argv[*i][j++]] = 1;
      opts->a_cnt++;
    }
  (*i)++;
}

t_opt		*tar_options(int argc, char **argv)
{
  t_opt		*opts;
  int		i;
  size_t	j;

  CHECK_V(opts = tar_init_opt(), NULL, NULL);
  CHECK_V(opts->folders = malloc(sizeof(char *) * argc), NULL, NULL);
  i = 1;
  opts->f_cnt = 0;
  opts->out = NULL;
  while (i < argc)
    {
      if ((argv[i][0] != '-' || argv[i][1] == '-') && !opts->out)
      	opts->out = argv[i++];
      else if (argv[i][0] != '-' || argv[i][1] == '-' && opts->out)
  	opts->folders[opts->f_cnt++] = argv[i++];
      else
  	tar_options_spec(opts, argv, &i);
    }
  return (opts);
}

int	tar_error(int type, int errno)
{
  if (type == ERR_USAGE)
    {
      printf("Usage : ./my_tar [-xvca] archive_file [to_archive1");
      printf("to_archive2 to_archiveN ...]\n");
    }
  else if (type == ERR_MALLOC)
    printf("./my_tar : malloc error\n");
  else if (type == ERR_GET)
    printf("./my_tar : fail to get files\n");
  else if (type == 0)
    perror("./my_tar ");
  exit(1);
}

int	main(int ac, char **av)
{
  t_opt *opts;
  int	i;

  i = 0;
  CHECK(opts = tar_options(ac, av), NULL, ERR_MALLOC);
  if (opts->is['x'] && opts->out)
    parse_header_and_create(opts);
  else if (opts->is['c'] && opts->f_cnt > 0)
    {
      (!opts->is['a']) ? fclose(fopen(opts->out, "w")) : 1;
      while (i < opts->f_cnt)
	tar_get(opts->folders[i++], opts);
    }
  else
    tar_error(ERR_USAGE, 0);
  return (0);
}
