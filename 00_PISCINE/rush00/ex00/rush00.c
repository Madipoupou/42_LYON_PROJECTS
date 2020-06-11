/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rush00.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: davfelix <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/08 12:16:24 by davfelix     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/08 14:52:25 by davfelix    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_display_line(char first_last, char middle, int length)
{
	ft_putchar(first_last);
	while (length > 2)
	{
		ft_putchar(middle);
		length--;
	}
	if (length == 2)
		ft_putchar(first_last);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	height;

	height = y;
	if (x <= 0 || y <= 0)
		return ;
	while (height >= 1)
	{
		if ((height == y || height == 1))
			ft_display_line('o', '-', x);
		if (height > 1 && height < y)
			ft_display_line('|', ' ', x);
		height--;
	}
	return ;
}
