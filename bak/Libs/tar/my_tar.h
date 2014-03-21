/*
** my_tar.h for my_tar in /home/aslafy_z/rendu/PSU_2013_my_tar
**
** Made by Zadkiel Aslafy Aharonian
** Login   <aslafy_z@epitech.net>
**
** Started on  Fri Nov 22 18:10:43 2013 Zadkiel Aslafy Aharonian
** Last update Sun Dec  1 19:20:30 2013 Zadkiel Aslafy-Aharonian
*/

#ifndef __MY_TAR_H__
#define __MY_TAR_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <utime.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <wchar.h>
#include <errno.h>
#include <string.h>
#include "my.h"

#define OCT2DEC(o)	 (atoi(convert_base((o), "01234567", "0123456789")))
#define CHECK_E(v, c)	 if ((v) == c) return (tar_error(0, errno));
#define CHECK_V(v, c, r) if ((v) == c) return (r);
#define CHECK(v, c, e) 	 if ((v) == c) return (tar_error(e, 0));
#define DOT_FILTER(s) (s[0] == '.' && (!s[1] || (s[1] == '.' && !s[2])))
#define ERR_USAGE	1
#define ERR_MALLOC	2
#define ERR_GET		3

typedef struct s_opt
{
  char	is[255];
  char	**folders;
  int	a_cnt;
  int	f_cnt;
  char	*out;
} t_opt;

typedef struct s_file
{
  struct stat	stat;
  char		*path;
} t_file;

typedef struct s_header
{
  char		*path;
  int		mode;
  int		uid;
  int		gid;
  int		size;
  time_t	time;
  int		cksum;
  int		type;
} t_header;

mode_t		itomode(int);
t_file		*tar_init_file();
t_opt		*tar_init_opt();
t_header	*tar_init_head(t_header *);
void		tar_free_file(t_file *);
void		tar_free_opt(t_opt *);
int		tar_get(char *, t_opt *);
int		tar_get_dir(char *, struct dirent *, t_opt *);
char		*tar_get_path(char *, char *, int);
t_opt		*tar_options(int, char **);
char		get_file_type(mode_t);
int		get_file_mode(mode_t);
int		get_control_sum(char *);
char		*get_file_size(t_file *);
int		parse_header_and_create(t_opt *);

#endif
