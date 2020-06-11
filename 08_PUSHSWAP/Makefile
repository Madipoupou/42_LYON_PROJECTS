NAME =		checker
NAME2 =		push_swap
SRC =		./src/main1.c
SRC2 =		./src/main2.c
OBJ =		$(SRC:.c=.o)
OBJ2 =		$(SRC2:.c=.o)
HEADER =	./includes/
CFLAGS =	-Wall -Werror -Wextra -I $(HEADER)
CC =		gcc

all: compile

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -L./libft -lft -o $(NAME)

$(NAME2): $(OBJ2)
	@$(CC) $(OBJ2) -L./libft -lft -o $(NAME2)

$(OBJ): %.o : %.c $(HEADER)
	@$(CC) -o $@ -c $< $(CFLAGS)

$(OBJ2): %.o : %.c $(HEADER)
	@$(CC) -o $@ -c $< $(CFLAGS)

compile:
	@$(MAKE) -s -C ./libft
	@$(MAKE) -s $(NAME)
	@$(MAKE) -s $(NAME2)

clean:
	@make -s -C ./libft clean
	@/bin/rm -f $(OBJ)
	@/bin/rm -f $(OBJ2)

fclean: clean
	@make -s -C ./libft fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(NAME2)

re: fclean all
