# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/07/19 03:52:35 by mhotting     #+#   ##    ##    #+#        #
#    Updated: 2018/07/19 16:41:26 by mhotting    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = cat 
CFLAGS = -Wall -Werror -Wextra
CC = gcc
SRCS =	./srcs/cat.c \
		./srcs/ft_readfile.c \
		./srcs/ft_error_manager.c \
		./srcs/ft_infinity_loop.c \
		./srcs/ft_strlen.c
OBJ =	cat.o \
		ft_readfile.o \
		ft_error_manager.o \
		ft_infinity_loop.o \
		ft_strlen.o

HEADER = ./includes

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) -I$(HEADER) -c $(SRCS)
	@gcc $(OBJ) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
