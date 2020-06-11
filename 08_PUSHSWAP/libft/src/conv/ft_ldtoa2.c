/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ldtoa2.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 18:05:15 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:07:34 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"
#include <stdio.h>

static int	ft_eval_size(long double f)
{
	int	res;

	if (f >= 0L && f < 1L)
		return (0);
	res = 0;
	while (!(f >= 0L && f < 1L))
	{
		f /= 10;
		res++;
	}
	return (res);
}

static void	ft_resize(long double *temp, int size, int type)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (type == 1)
			*temp = *temp * 10;
		else
			*temp = *temp / 10;
		i++;
	}
}

void		ft_ldint_extract(char *res, long double *f)
{
	int			size;
	int			ext;
	long double	temp;
	int			i;

	i = (res[0] == '-' ? 1 : 0);
	size = ft_eval_size(*f);
	if (size == 0)
	{
		res[i] = '0';
		return ;
	}
	size -= 1;
	while (size >= 0)
	{
		printf("F: %Lf\n", *f);
		temp = *f;
		ft_resize(&temp, size, -1);
		ext = (int)temp;
		res[i++] = ext + '0';
		temp = (long double)ext;
		ft_resize(&temp, size, 1);
		size--;
		*f -= temp;
	}
}
