/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rush02.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: davfelix <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/08 15:31:48 by davfelix     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/08 15:46:51 by davfelix    ###    #+. /#+    ###.fr     */
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
		if (height == y)
		{
			ft_display_line('A', 'B', x);
		}
		else if (height > 1 && height < y)
		{
			ft_display_line('B', ' ', x);
		}
		else if (height == 1)
		{
			ft_display_line('C', 'B', x);
		}
		height--;
	}
	return ;
}
