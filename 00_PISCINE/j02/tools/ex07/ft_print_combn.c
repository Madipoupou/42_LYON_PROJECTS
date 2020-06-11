/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_combn.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/05 20:42:44 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/05 23:38:32 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_putchar(char c);

int		test_valid(int *tab, int n)
{
	int i;
	int res_test;

	i = 0;
	res_test = 1;
	while (i < n - 1)
	{
		if (tab[i] >= tab[i + 1])
		{
			res_test = 0;
			break ;
		}
		i++;
	}
	return (res_test);
}

void	init_tab(int *tab, int n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		tab[i] = tab[i - 1] + 1;
		i++;
	}
}

void	print_tab(int *tab, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(tab[i] + 48);
		i++;
	}
	if (tab[0] < (10 - n))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combn(int n)
{
	int	tab[9];
	int	i;

	tab[0] = 0;
	init_tab(tab, n);
	while (tab[0] <= (10 - n))
	{
		i = 0;
		while (tab[n - 1 - i] <= 9)
		{
			if (test_valid(tab, n))
				print_tab(tab, n);
			tab[n - 1 - i]++;
		}
		i++;
		while (n - i > 0)
		{
			if (tab[n - i] == 10)
			{
				tab[n - i] = 0;
				tab[n - 1 - i]++;
			}
			i++;
		}
	}
}
