/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_range.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/11 22:26:11 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 10:10:44 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		i;
	int		*tab;
	long	size;

	size = max - min;
	if (min > max)
		return (0);
	tab = (int*)malloc(sizeof(int) * (max));
	if (!tab)
		return (0);
	i = 0;
	while ((i + min) < max)
	{
		*(tab + i) = i + min;
		i++;
	}
	return (tab);
}
