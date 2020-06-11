/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/05 15:50:16 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/05 20:26:34 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	int	diviseur;
	int mod;
	int limit_test;
	int	is_limit;

	diviseur = 1000000000;
	mod = 10;
	limit_test = 0;
	if (nb == -2147483648)
		limit_test = 1;
	if (limit_test)
		nb += 1;
	while (nb / diviseur == 0)
		diviseur /= 10;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	ft_putchar(nb / diviseur + 48);
	while ((diviseur /= 10) >= 1)
	{
		is_limit = (diviseur == 1 && limit_test == 1);
		is_limit ? ft_putchar('8') : ft_putchar((nb / diviseur) % 10 + 48);
	}
}
