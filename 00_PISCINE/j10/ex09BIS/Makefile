# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/07/17 14:14:47 by mhotting     #+#   ##    ##    #+#        #
#    Updated: 2018/07/17 14:31:54 by mhotting    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = ft_advanced_do-op
CFLAGS = -Wextra -Wall -Werror
SRCS =	./srcs/do_op.c \
		./srcs/ft_add.c \
		./srcs/ft_atoi.c \
		./srcs/ft_div.c \
		./srcs/ft_mod.c \
		./srcs/ft_mul.c \
		./srcs/ft_putchar.c \
		./srcs/ft_putnbr.c \
		./srcs/ft_putstr.c \
		./srcs/ft_select_op.c \
		./srcs/ft_sub.c \
		./srcs/ft_usage.c
OBJECTS =	do_op.o \
			ft_add.o \
			ft_atoi.o \
			ft_div.o \
			ft_mod.o \
			ft_mul.o \
			ft_putchar.o \
			ft_putnbr.o \
			ft_putstr.o \
			ft_select_op.o \
			ft_sub.o \
			ft_usage.o
HEADER1 = includes
HEADER2 = ./

all: create_prog

create_prog:
	gcc $(CFLAGS) -I$(HEADER1) -I$(HEADER2) -c $(SRCS)
	gcc $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
	/bin/rm -f $(OBJECTS)

fclean:
	/bin/rm -f $(NAME)

re: fclean all
