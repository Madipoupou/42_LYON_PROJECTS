/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_words_tables.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 05:18:28 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 02:38:55 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

void	ft_print_word_tables(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != 0)
	{
		my_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}
