/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/10 23:34:24 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/10 23:42:12 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/10 11:54:32 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/10 23:31:34 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_putchar(char c);

void	str_addchar(char c, char *str)
{
	int i;
	int cpt;

	cpt = 0;
	while (str[cpt] != '\0')
		cpt++;
	if (cpt == 0)
	{
		str[0] = c;
		str[1] = '\0';
	}
	else
	{
		i = 0;
		while (str[i] != '\0')
			i++;
		str[i] = c;
		str[i+1] = '\0';
	}
}

void	convert_digits(char *result, char *base)
{
	int i;
	int dig;

	i = 0;
	while (result[i] != '\0')
	{
		if (result[i] >= '0' && result[i] <= '9')
			dig = result[i] - '0';
		else if (result[i] >= 65 && result[i] <= 90)
			dig = result[i] - 'A';
		result[i] = base[dig];
		ft_putchar(result[i]);
		i++;
	}
}

void	add_digits(int nbr, int base_size, char *resultat, char *tab)
{
	if (nbr / base_size ==  0)
	{
		str_addchar(tab[nbr % base_size], resultat);
		return ;
	}
	add_digits((nbr / base_size), base_size, resultat, tab);
	str_addchar(tab[nbr % base_size], resultat);
}

int		error_base(char *str)
{
	int i;
	int j;
	
	if (str[0] == '\0')
		return (1);
	if (str[1] == '\0')
		return (1);
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '+' || str[i] == '-') || (str[i] < 32 || str[i] > 126))
			return (1);
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_size;
	char	result[100];
	char	tab[36];

	if (error_base(base))
		return;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	base_size = -1;
	while (++base_size < 35)
	{
		if (base_size < 10)
			tab[base_size] = '0' + base_size;
		else
			tab[base_size] = 'A' + base_size - 10;

	}
	base_size = 0;
	while (base[base_size] != '\0')
		base_size++;
	add_digits(nbr, base_size, result, tab);
	convert_digits(result, base);
}
