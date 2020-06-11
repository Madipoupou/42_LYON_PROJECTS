/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_comb2.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/05 13:14:26 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/05 15:27:26 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = -1;
	while (++num1 <= 99)
	{
		num2 = num1;
		while (++num2 <= 99)
		{
			if (num1 < num2)
			{
				ft_putchar(num1 / 10 + 48);
				ft_putchar(num1 % 10 + 48);
				ft_putchar(' ');
				ft_putchar(num2 / 10 + 48);
				ft_putchar(num2 % 10 + 48);
				if (num1 != 98 || num2 != 99)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}
