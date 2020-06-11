# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/07/17 02:04:26 by mhotting     #+#   ##    ##    #+#        #
#    Updated: 2018/07/17 11:37:33 by mhotting    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME=do-op
CFLAGS=-Wall -Wextra -Werror
SRCS=	./srcs/do_op.c \
		./srcs/ft_feed_tab.c \
		./srcs/ft_putchar.c \
		./srcs/ft_putstr.c \
		./srcs/ft_atoi.c \
		./srcs/ft_op_def.c \
		./srcs/ft_putnbr.c \
		./srcs/ft_test_op.c
OBJ=	do_op.o \
		ft_feed_tab.o \
		ft_putchar.o \
		ft_putstr.o \
		ft_atoi.o \
		ft_op_def.o \
		ft_putnbr.o \
		ft_test_op.o
HEADER=./includes

all: create_prog

create_prog:
	@gcc -I$(HEADER) -c $(SRCS)
	@gcc $(OBJ) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean:
	@/bin/rm -f $(NAME)

re: fclean all
