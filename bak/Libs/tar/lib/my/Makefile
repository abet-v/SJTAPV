##
## Makefile for lib in /home/aslafy_z/rendu/Piscine-C-lib/my
##
## Made by Zadkiel Aslafy Aharonian
## Login   <aslafy_z@epitech.net>
##
## Started on  Mon Oct 21 11:21:36 2013 Zadkiel Aslafy Aharonian
## Last update Sun Dec  1 17:20:40 2013 Zadkiel Aslafy-Aharonian
##

SRC=	my_find_prime_sup.c \
	my_printf_assign.c \
	my_printf.c \
	match.c \
	my_alignstr.c \
	my_memset.c \
	my_printf_deps.c \
	my_printf_flags1.c \
	my_printf_flags2.c \
	my_printf_flags3.c \
	my_printf_init.c \
	my_nbrlen.c \
	my_isnum.c \
	my_complete_str.c \
	my_char_to_str.c \
	convert_base.c \
	my_atoi.c \
	my_strcpos.c \
	my_strcut.c \
	my_getintnbr.c \
	my_getuintnbr.c \
	my_str_getpos.c \
	my_strccat.c \
	my_strrecat.c \
	my_strlen_prtb.c \
	my_instr.c \
	my_getnbr_base.c \
	my_makecstr.c \
	my_trimstr.c \
	my_getnbr.c \
	my_isneg.c \
	my_is_prime.c \
	my_power_rec.c \
	my_putchar.c \
	my_putnbr_base.c \
	my_put_nbr.c \
	my_putstr.c \
	my_revstr.c \
	my_showmem.c \
	my_showstr.c \
	my_show_wordtab.c \
	my_sort_int_tab.c \
	my_square_root.c \
	my_strcapitalize.c \
	my_strcat.c \
	my_strcmp.c \
	my_strcpy.c \
	my_strdup.c \
	my_str_isalpha.c \
	my_str_islower.c \
	my_str_isnum.c \
	my_str_isprintable.c \
	my_str_isupper.c \
	my_strlcat.c \
	my_strlen.c \
	my_strlowcase.c \
	my_strncat.c \
	my_strncmp.c \
	my_strncpy.c \
	my_strstr.c \
	my_str_to_wordtab.c \
	my_strupcase.c \
	my_swap.c \
	my_str_replace.c \
	my_putgetnbr_base.c

HEADS=	my.h \
	my_printf.h

HEADZ=	../my.h \
	../my_printf.h

OBJ=	$(SRC:.c=.o)

all:	$(OBJ)
	ar rc ../libmy.a $(OBJ)
	ranlib ../libmy.a
	cp $(HEADS) ../

clean:
	rm -f $(OBJ)

re:	fclean all

fclean:	clean
	echo "$(HEADZ)" | xargs rm -f
	rm -f ../libmy.a
