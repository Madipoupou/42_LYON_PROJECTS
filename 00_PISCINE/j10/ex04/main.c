/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/16 23:52:40 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 00:05:11 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>

int	ft_count_if(char **tab, int (*f)(char*));

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
	char *tab[] = { "bab", "cac", "gag", 0 };
	int (*f)(char*);
	f = &ft_check;
	printf("%d\n", ft_count_if(tab, f));
	return (0);
}
