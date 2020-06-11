# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/27 18:14:08 by mhotting     #+#   ##    ##    #+#        #
#    Updated: 2018/10/27 18:20:39 by mhotting    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME =		fillit
SRCS =		fillit.c		\
			util.c			\
			errors.c		\
			ft_readfile.c	\
			ft_checkshape.c	\
			ft_solve.c		\
			fill.c
OBJ =		$(SRCS:.c=.o)
HEADER =	./fillit.h
CFLAGS = 	-Wall -Wextra -Werror -I $(HEADER)
CC =		gcc

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C ./libft
	@$(CC) $(OBJ) -L./libft -lft -o $(NAME)

$(OBJ): %.o : %.c $(HEADER)
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@make -C ./libft clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C ./libft fclean
	@/bin/rm -f $(NAME)

re: fclean all
