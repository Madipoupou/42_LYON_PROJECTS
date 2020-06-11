# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jde-mour <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/07/21 12:58:47 by jde-mour     #+#   ##    ##    #+#        #
#    Updated: 2018/07/22 16:52:35 by mhotting    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME0 = colle-00
NAME1 = colle-01
NAME2 = colle-02
NAME3 = colle-03
NAME4 = colle-04
NAME5 = colle-2

SRC0 = srcs/colle_00.c
SRC1 = srcs/colle_01.c
SRC2 = srcs/colle_02.c
SRC3 = srcs/colle_03.c
SRC4 = srcs/colle_04.c
SRC5 = srcs2/colle_2.c

OBJ0 = colle_00.o
OBJ1 = colle_01.o
OBJ2 = colle_02.o
OBJ3 = colle_03.o
OBJ4 = colle_04.o
OBJ5 = colle_2.o

HDR = includes/my.h
HDR2 = includes/my2.h

SRCALL = srcs/ft_atoi.c \
		 srcs/ft_putchar.c \
		 srcs/main.c \
		 srcs/ft_print_line.c

SRCALL2 = srcs2/ft_disp.c \
		  srcs2/ft_create_elem.c \
		  srcs2/ft_clean_list.c \
		  srcs2/ft_fill_list.c \
		  srcs2/ft_parse.c \
		  srcs2/ft_possib.c \
		  srcs2/ft_putstr.c \
		  srcs2/ft_putnbr.c \
		  srcs2/ft_util_tab.c

SRCALLO = ft_atoi.o \
		  ft_putchar.o \
		  main.o \
		  ft_print_line.o

SRCALLO2 = ft_disp.o \
		   ft_create_elem.o \
		   ft_fill_list.o \
		   ft_clean_list.o \
		   ft_parse.o \
		   ft_possib.o \
		   ft_putstr.o \
		   ft_putnbr.o \
		   ft_util_tab.o

FLAGS = -Wall -Werror -Wextra

all: $(SRCALLO2) $(SRCALLO) $(NAME0) $(NAME1) $(NAME2) $(NAME3) $(NAME4) $(NAME5)

$(SRCALLO2): $(SRCALL2)
	@cc $(FLAGS) -I $(HDR2) -c $(SRCALL2)
$(SRCALLO): $(SRCALL)
	@cc $(FLAGS) -I $(HDR) -c $(SRCALL)
$(NAME0): $(SRCALLO) $(SRC0)
	@cc $(FLAGS) -I $(HDR) -c $(SRC0)
	@cc $(OBJ0) $(SRCALLO) -o $(NAME0)
$(NAME1): $(SCRALLO) $(SRC1)
	@cc $(FLAGS) -I $(HDR) -c $(SRC1)
	@cc $(OBJ1) $(SRCALLO) -o $(NAME1)
$(NAME2): $(SRCALLO) $(SRC2)
	@cc $(FLAGS) -I $(HDR) -c $(SRC2)
	@cc $(OBJ2) $(SRCALLO) -o $(NAME2)
$(NAME3): $(SCRALLO) $(SRC3)
	@cc $(FLAGS) -I $(HDR) -c $(SRC3)
	@cc $(OBJ3) $(SRCALLO) -o $(NAME3)
$(NAME4): $(SRCALLO) $(SRC4)
	@cc $(FLAGS) -I $(HDR) -c $(SRC4)
	@cc $(OBJ4) $(SRCALLO) -o $(NAME4)
$(NAME5): $(SRCALLO2) $(SRC5)
	@cc $(FLAGS) -I $(HDR2) -c $(SRC5)
	@cc $(OBJ5) $(SRCALLO2) -o $(NAME5)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME0) $(NAME1) $(NAME2) $(NAME3) $(NAME4) $(NAME5)

re: fclean all
