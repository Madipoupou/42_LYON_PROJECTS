/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/16 23:09:03 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/16 23:31:25 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>

void	ft_foreach(int *tab, int length, void (*f)(int));

void	ft_addone(int a)
{
	printf("%d ", a);
}

void	increment(int *tab, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		tab[i]++;
		i++;
	}
}

int		main(void)
{
	int i;
	int tab[] = {1, 2, 3, 4, 5};
	void (*f_ptr)(int);

	f_ptr = &ft_addone;
	i = 0;
	while (i < 5)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	ft_foreach(tab, 5, f_ptr);
	i = 0;
	while (i < 5)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
}
