/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_comb.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/05 10:55:56 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/05 13:09:24 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb(void)
{
	int	tab[3];

	tab[0] = '0' - 1;
	while (++tab[0] <= '7')
	{
		tab[1] = tab[0];
		while (++tab[1] <= '9')
		{
			tab[2] = tab[1];
			while (++tab[2] <= '9')
			{
				if (tab[0] < tab[1] && tab[1] < tab[2])
				{
					ft_putchar(tab[0]);
					ft_putchar(tab[1]);
					ft_putchar(tab[2]);
					if (tab[0] != '7')
					{
						ft_putchar(',');
						ft_putchar(' ');
					}
				}
			}
		}
	}
}
