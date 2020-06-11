/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_spy.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/13 05:57:53 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/13 06:13:44 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

int		my_strlen3(char *str)
{
	int cpt;

	cpt = 0;
	while (str[cpt] != '\0')
		cpt++;
	return (cpt);
}

int		ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	mem_i;

	if (my_strlen3(to_find) == 0)
		return (0);
	i = -1;
	while (++i < my_strlen3(str))
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			mem_i = i;
			while (++j < my_strlen3(to_find) && ++i < my_strlen3(str))
			{
				if (str[i] != to_find[j])
					break ;
			}
			if (j == my_strlen3(to_find))
				return (1);
			i = mem_i;
		}
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		ft_putchar(*(str + i));
		i++;
	}
}

int		main(int argc, char **argv)
{
	int	i;
	int	test;

	if (argc == 1)
		return (0);
	i = 1;
	test = 0;
	while (i < argc)
	{
		test = ft_strstr(argv[i], "president");
		test = test || ft_strstr(argv[i], "attack");
		test = test || ft_strstr(argv[i], "Bauer");
		if (test)
			break ;
		i++;
	}
	if (test)
		ft_putstr("Alert!!!\n");
	return (0);
}
