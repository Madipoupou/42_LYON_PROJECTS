# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/30 15:23:47 by mhotting     #+#   ##    ##    #+#        #
#    Updated: 2018/11/11 20:50:46 by mhotting    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME =		fdf
SRCS =		./src/main.c				\
			./src/error.c				\
			./src/coord_tools.c			\
			./src/util.c				\
			./src/draw_line.c			\
			./src/ft_display.c			\
			./src/event_manager.c		\
			./src/matrix_generator.c	\
			./src/slide.c				\
			./src/zoom.c				\
			./src/height.c				\
			./src/color.c				\
			./src/context.c				\
			./src/rotate.c
OBJ =		$(SRCS:.c=.o)
HEADER =	./includes/
CFLAGS = 	-Wall -Wextra -Werror -I $(HEADER)
CC =		gcc

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C ./libft
	@make -s -C ./minilibx
	@$(CC) $(OBJ) -L./libft -lft -L./minilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ): %.o : %.c $(HEADER)
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@make -s -C ./libft clean
	@make -s -C ./minilibx clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -s -C ./libft fclean
	@make -s -C ./minilibx fclean
	@/bin/rm -f $(NAME)

re: fclean all
