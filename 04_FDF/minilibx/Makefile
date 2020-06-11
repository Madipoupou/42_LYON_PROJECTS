# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/30 15:32:50 by mhotting     #+#   ##    ##    #+#        #
#    Updated: 2018/10/30 15:33:44 by mhotting    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NOM 	=	libmlx.a
SRC 	=	mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1 	=	$(SRC:.c=.o)
OBJ		=	$(OBJ1:.m=.o)
CFLAGS+=-O2

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)

clean:
	@rm -f mlx_app

fclean: clean
	@rm -f $(NOM) $(OBJ) *~

re: fclean all
