# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/07/16 21:02:59 by mhotting     #+#   ##    ##    #+#        #
#    Updated: 2018/07/17 21:19:59 by mhotting    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME=libft.a
CFLAGS=-Wall -Wextra -Werror
SRCS=srcs/ft_putchar.c \
	 srcs/ft_putstr.c \
	 srcs/ft_strcmp.c \
	 srcs/ft_strlen.c \
	 srcs/ft_swap.c
OBJ= ft_putchar.o \
	 ft_putstr.o \
	 ft_strcmp.o \
	 ft_strlen.o \
	 ft_swap.o
HEADER=includes

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -I$(HEADER) -c $(SRCS)
	ar -rv $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)


fclean:
	/bin/rm -f $(NAME)

re: fclean all
