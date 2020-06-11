/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rush01.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kanne <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/07 14:51:44 by kanne        #+#   ##    ##    #+#       */
/*   Updated: 2018/07/08 12:25:06 by davfelix    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_display_line(char first, char fill, char last, int length)
{
	ft_putchar(first);
	while (length > 2)
	{
		ft_putchar(fill);
		length = length - 1;
	}
	if (length == 2)
	{
		ft_putchar(last);
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int height;

	height = y;
	if (x <= 0 || y <= 0)
	{
		return ;
	}
	while (height >= 1)
	{
		if (height == y)
		{
			ft_display_line(47, '*', 92, x);
		}
		else if (height == 1)
		{
			ft_display_line(92, '*', 47, x);
		}
		else if (height > 1 && height < y)
		{
			ft_display_line('*', ' ', '*', x);
		}
		height--;
	}
}
