# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/07/22 22:28:09 by mhotting     #+#   ##    ##    #+#        #
#    Updated: 2018/07/22 22:39:37 by mhotting    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = eval_expr

SRC = ./srcs/ft_atoi.c \
	  ./srcs/ft_eval_subexpr.c \
	  ./srcs/ft_operations.c \
	  ./srcs/ft_putnbr.c \
	  ./srcs/ft_str_manager.c \
	  ./srcs/ft_do_op.c \
	  ./srcs/ft_func.c \
	  ./srcs/ft_par_manager.c \
	  ./srcs/ft_putstr.c \
	  ./srcs/ft_strlen.c \
	  ./srcs/ft_eval_expr.c \
	  ./srcs/ft_itoa.c \
	  ./srcs/ft_putchar.c \
	  ./srcs/ft_remove_ws.c \
	  ./srcs/main.c

OBJ = ft_atoi.o \
	  ft_eval_subexpr.o \
	  ft_operations.o \
	  ft_putnbr.o \
	  ft_str_manager.o \
	  ft_do_op.o \
	  ft_func.o \
	  ft_par_manager.o \
	  ft_putstr.o \
	  ft_strlen.o \
	  ft_eval_expr.o \
	  ft_itoa.o \
	  ft_putchar.o \
	  ft_remove_ws.o \
	  main.o

HDR = ./includes

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) -I $(HDR) -c $(SRC)
	@gcc $(OBJ) -o $(NAME)

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
