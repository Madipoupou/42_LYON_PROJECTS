# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/02 08:24:04 by mhotting     #+#   ##    ##    #+#        #
#    Updated: 2018/12/28 15:35:51 by mhotting    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME	=	libft.a
SRCDIR	=	./src
OBJDIR	=	./obj

SRCS	:=	$(shell find $(SRCDIR) -name '*.c')
SRCDIRS	:=	$(shell find . -name '*.c' -exec dirname {} \; | uniq)
SRCDIRS	:=	$(shell find . -name '*.c' -exec dirname {} \; | uniq | sed 's/\/src//g')
OBJS	:=	$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

HEADER =	./includes
CFLAGS =	-Wall -Werror -Wextra -I $(HEADER)
CC =		gcc

all: $(NAME)

$(NAME): buildrepo $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -I $(HEADER) -o $@

.PHONY: clean fclean re

clean:
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

buildrepo:
	@$(call make-repo)

define make-repo
	mkdir -p $(OBJDIR)
	for dir in $(SRCDIRS); \
	do \
		mkdir -p $(OBJDIR)/$$dir; \
	done
endef
