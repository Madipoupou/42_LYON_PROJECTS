# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/02 08:24:04 by mhotting     #+#   ##    ##    #+#        #
#    Updated: 2018/10/18 10:20:09 by mhotting    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME =		libft.a
SRCS =		./src/string/ft_strlen.c		\
			./src/mem/ft_bzero.c			\
			./src/mem/ft_memset.c			\
			./src/mem/ft_memcpy.c			\
			./src/mem/ft_memccpy.c			\
			./src/mem/ft_memmove.c			\
			./src/mem/ft_memchr.c			\
			./src/mem/ft_memcmp.c			\
			./src/string/ft_strdup.c		\
			./src/string/ft_strcpy.c		\
			./src/string/ft_strncpy.c		\
			./src/string/ft_strcat.c		\
			./src/string/ft_strncat.c		\
			./src/string/ft_strlcat.c		\
			./src/string/ft_strchr.c		\
			./src/string/ft_strrchr.c		\
			./src/string/ft_strstr.c		\
			./src/string/ft_strnstr.c		\
			./src/string/ft_strcmp.c		\
			./src/string/ft_strncmp.c		\
			./src/conv/ft_atoi.c			\
			./src/type/ft_isalpha.c			\
			./src/type/ft_isdigit.c			\
			./src/type/ft_isalnum.c			\
			./src/type/ft_isascii.c			\
			./src/type/ft_isprint.c			\
			./src/type/ft_toupper.c			\
			./src/type/ft_tolower.c			\
			./src/io/ft_putchar.c			\
			./src/io/ft_putstr.c			\
			./src/io/ft_putendl.c			\
			./src/io/ft_putnbr.c			\
			./src/io/ft_putchar_fd.c		\
			./src/io/ft_putstr_fd.c			\
			./src/io/ft_putendl_fd.c		\
			./src/io/ft_putnbr_fd.c			\
			./src/mem/ft_memalloc.c			\
			./src/mem/ft_memdel.c			\
			./src/string/ft_strnew.c		\
			./src/string/ft_strdel.c		\
			./src/string/ft_strclr.c		\
			./src/string/ft_striter.c		\
			./src/string/ft_striteri.c		\
			./src/string/ft_strmap.c		\
			./src/string/ft_strmapi.c		\
			./src/string/ft_strequ.c		\
			./src/string/ft_strnequ.c		\
			./src/string/ft_strsub.c		\
			./src/string/ft_strjoin.c		\
			./src/string/ft_strtrim.c		\
			./src/conv/ft_itoa.c			\
			./src/string/ft_strsplit.c		\
			./src/list/ft_lstnew.c			\
			./src/list/ft_lstdelone.c		\
			./src/list/ft_lstdel.c			\
			./src/list/ft_lstadd.c			\
			./src/list/ft_lstiter.c			\
			./src/list/ft_lstmap.c			\
			./src/conv/ft_itoabase.c		\
			./src/string/ft_sortstrtab.c	\
			./src/list/ft_lstaddend.c		\
			./src/list/ft_lstlen.c			\
			./src/list/ft_lstswap_c.c		\
			./src/list/ft_lstsort_bc.c 		\
			./src/list/ft_lststrdel.c		\
			./src/list/ft_lstremove.c
OBJ =		$(SRCS:.c=.o)
HEADER =	./includes
CFLAGS = 	-Wall -Wextra -Werror -I $(HEADER)
CC =		gcc

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): %.o : %.c $(HEADER)
	@gcc -o $@ -c $< $(CFLAGS)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
