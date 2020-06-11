/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/16 23:52:40 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 00:00:23 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>

int	ft_any(char **tab, int (*f)(char*));

int	ft_check(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'a')
			return (1);
		i++;
	}
	return (0);
}

int	main(void)
{
	char *tab[] = { "bab", "ccc", "ggg", 0 };
	int (*f)(char*);
	f = &ft_check;
	printf("%d\n", ft_any(tab, f));
	return (0);
}
