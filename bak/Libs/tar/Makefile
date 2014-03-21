##
## Makefile for my_ls in /home/aslafy_z/rendu/PSU_2013_my_ls
## 
## Made by Zadkiel Aslafy Aharonian
## Login   <aslafy_z@epitech.net>
## 
## Started on  Fri Nov 22 18:11:38 2013 Zadkiel Aslafy Aharonian
## Last update Sun Dec  1 16:49:44 2013 Zadkiel Aslafy-Aharonian
##

NAME =	my_tar

CC =	gcc

RM =	rm -f

CFLAGS += -I ./lib/ -g3
LDFLAGS = -L ./lib/ -lmy

SRCS = 	my_tar.c \
	my_tar_init.c \
	my_tar_get.c \
	my_tar_misc.c \
	my_archive.c \
	my_unarchive.c \
	itomode.c

OBJS = 	$(SRCS:.c=.o)

all: 	$(NAME)

$(NAME):$(OBJS)
	make -C ./lib/my/ re
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)
	make -C ./lib/my/ clean

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
