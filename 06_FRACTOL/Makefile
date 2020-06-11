# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/13 19:10:45 by mhotting     #+#   ##    ##    #+#        #
#    Updated: 2019/01/14 13:48:15 by mhotting    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME =		fractol
SRCS =		./src/main.c				\
			./src/keyboard_manager.c	\
			./src/mouse_manager.c		\
			./src/context.c				\
			./src/context2.c			\
			./src/menu.c				\
			./src/error.c				\
			./src/init_frac.c			\
			./src/mandelbrot.c			\
			./src/julia.c				\
			./src/util.c				\
			./src/color.c				\
			./src/color2.c
OBJ =		$(SRCS:.c=.o)
LFT =		./libft/
MLX =		./minilibx/
HEADER =	./includes/
CFLAGS = 	-Wall -Werror -Wextra -I $(HEADER)
CC =		gcc

all: compile

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -L./libft -lft -L./minilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ): %.o : %.c $(HEADER) $(LFT)libft.a $(MLX)libmlx.a
	@$(CC) -o $@ -c $< $(CFLAGS)

compile:
	@$(MAKE) -s -C ./libft
	@$(MAKE) -s -C ./minilibx
	@$(MAKE) $(NAME)

clean:
	@make -s -C ./libft clean
	@make -s -C ./minilibx clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -s -C ./libft fclean
	@make -s -C ./minilibx fclean
	@/bin/rm -f $(NAME)

re: fclean all
