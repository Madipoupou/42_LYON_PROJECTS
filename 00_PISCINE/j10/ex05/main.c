/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 00:10:03 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 00:13:33 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int));

int	ft_test(int a, int b)
{
	if (a < b)
		return (-1);
	else if (a == b)
		return (0);
	return (1);
}

int main(void)
{
	int tab[] = { 1, 2, -1, 4, 5 };
	int (*f)(int, int);

	f = &ft_test;
	printf("%d\n", ft_is_sort(tab, 5, f));
	return (0);
}
