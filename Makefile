##
## Makefile for  in /home/Wasx/CPool_Day12
## 
## Made by Wassim ALKAYAR
## Login   <Wasx@epitech.net>
## 
## Started on  Wed Mar 15 10:16:14 2017 Wassim ALKAYAR
## Last update Sat Apr 29 14:31:03 2017 Wassim Alkayar
##

NAME	=	my_ls

SRC	=	main.c			\
		src/ls.c		\
		src/ls_l.c		\
		src/ls_R.c		\
		src/ls_R_l.c		\
		src/ls_t.c		\
		src/utils3.c		\
		src/utils4.c		\
		src/utils5.c		\
		src/utils6.c		\
		src/utils7.c		\
		src/my_alphacmp.c	\
		src/my_strlowcase.c	\
		src/utils.c		\
		src/utils2.c		\
		src/create_dlistargc.c	\
		src/print_dlist.c	\
		src/print_files.c	\
		src/push_back_dlist.c	\
		src/push_front_dlist.c	\
		src/errorsystem.c	\
		src/sort_list.c		\
		src/is_empty_dlist.c

SRC2	=	libmy.a

CFLAGS	+=	-g3 -Wall -Werror -Wextra -I./include

OBJ	=	$(SRC:.c=.o)

GCC	=	gcc -o

RM	=	rm -f

ASUPR2	=	my_ls

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(NAME) $(OBJ) $(SRC2) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(ASUPR2)

re:	fclean all

.PHONY: all clean fclean re
