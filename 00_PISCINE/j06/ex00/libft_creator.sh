# .o file creations
gcc -c ft_putchar.c -o ft_putchar.o
gcc -c ft_putstr.c -o ft_putstr.o
gcc -c ft_swap.c -o ft_swap.o
gcc -c ft_strlen.c -o ft_strlen.o
gcc -c ft_strcmp.c -o ft_strcmp.o

# libft creation
ar rc libft.a ft_putchar.o ft_putstr.o ft_swap.o ft_strlen.o ft_strcmp.o
