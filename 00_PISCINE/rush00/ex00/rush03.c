/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rush03.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/08 17:55:30 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/08 18:28:51 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_putchar(char c);

void	display_line(char first, char middle, char last, int x)
{
	int	cpt;

	if (x == 1)
	{
		ft_putchar(first);
	}
	else
	{
		cpt = 0;
		while (cpt < x)
		{
			if (cpt == 0)
				ft_putchar(first);
			else if (cpt == (x - 1))
				ft_putchar(last);
			else
				ft_putchar(middle);
			cpt++;
		}
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	cpt;

	if (x <= 0 || y <= 0)
		return ;
	cpt = 0;
	while (cpt < y)
	{
		if (cpt == 0 || cpt == (y - 1))
			display_line('A', 'B', 'C', x);
		else
			display_line('B', ' ', 'B', x);
		cpt++;
	}
	return ;
}
