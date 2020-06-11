# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/07/19 03:52:35 by mhotting     #+#   ##    ##    #+#        #
#    Updated: 2018/07/19 04:09:20 by mhotting    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = ft_display_file
CFLAGS = -Wall -Werror -Wextra
CC = gcc
SRCS =	./srcs/main.c \
		./srcs/ft_readfile.c
OBJ =	main.o \
		ft_readfile.o
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
