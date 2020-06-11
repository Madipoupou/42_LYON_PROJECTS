/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ultimate_range.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/11 23:41:56 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 23:43:27 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;

	if (min > max)
	{
		range = NULL;
		return (0);
	}
	*range = (int*)malloc((max - min) * sizeof(int));
	if (!(*range))
		return (0);
	i = 0;
	while ((i + min) < max)
	{
		*((*range) + i) = i + min;
		i++;
	}
	return (i);
}
