/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_params.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/11 17:23:55 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/11 17:46:26 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_putchar(char c);

int		my_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

int		my_strcmp(char *s1, char *s2)
{
	if (my_strlen(s1) > 0 && my_strlen(s2) > 0)
	{
		if (s1[0] == s2[0])
			return (my_strcmp(&s1[1], &s2[1]));
		return ((int)(s1[0] - s2[0]));
	}
	else if (my_strlen(s1) == 0)
		return (0 - (int)s2[0]);
	else
		return ((int)s1[0]);
}

void	my_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	order_param(char **str_tab, int max)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < (max - 1))
	{
		j = i + 1;
		while (j < max)
		{
			if (my_strcmp(str_tab[i], str_tab[j]) > 0)
			{
				temp = str_tab[i];
				str_tab[i] = str_tab[j];
				str_tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int		i;

	if (argc == 1)
		return (0);
	order_param(argv, argc);
	i = 1;
	while (i < argc)
	{
		my_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
}
