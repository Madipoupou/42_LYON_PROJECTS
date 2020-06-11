/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/16 23:37:04 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/16 23:46:38 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>

int		*ft_map(int *tab, int length, int(*f)(int));

void	ft_print_tab(int *tab, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		if (i < length - 1)
			printf("%d - ", tab[i]);
		else
			printf("%d\n", tab[i]);
		i++;
	}
}

int		increment_tab(int a)
{
	a++;
	return (a);
}

int 	main(void)
{
	int tab[] = { 1, 2, 3, 4, 5};
	int *tab2;
	int (*f)(int);

	f = &increment_tab;
	tab2 = ft_map(tab, 5, f);
	ft_print_tab(tab, 5);
	ft_print_tab(tab2, 5);
	return (0);
} 
