/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 14:48:53 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 01:43:53 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fdf.h"

void		ft_putrgb(char **color)
{
	char	*temp;
	size_t	i;
	size_t	j;

	temp = ft_strnew(6);
	i = 6;
	while (i > ft_strlen(*color))
	{
		temp[(i - 6) * -1] = '0';
		i--;
	}
	j = 0;
	while (i > 0)
	{
		temp[(i - 6) * -1] = (*color)[j];
		i--;
		j++;
	}
	free(*color);
	*color = temp;
}

char		ft_hextochar(char a, char b)
{
	char	c1;
	char	c2;

	if (a >= 0 && a <= 9)
		c1 = a - '0';
	else
		c1 = a - 'a' + 10;
	if (b >= 0 && b <= 9)
		c2 = b - '0';
	else
		c2 = b - 'a' + 10;
	return (16 * c1 + c2);
}

static void	ft_changematrixcol(int color, int *size, void **ptr)
{
	int	***matrix;
	int	i;
	int	j;

	matrix = (int ***)ptr[3];
	i = 0;
	while (i < size[0])
	{
		j = 0;
		while (j < size[1])
		{
			matrix[i][j][2] = color;
			j++;
		}
		i++;
	}
}

void		ft_changecolor(void **ptr)
{
	int	color;
	int	***matrix;
	int	*size;

	matrix = (int ***)ptr[3];
	color = matrix[0][0][2];
	size = (int *)ptr[5];
	if (color == 16777215)
		color = 65280;
	else if (color == 65280)
		color = 31231;
	else if (color == 31231)
		color = 15335169;
	else if (color == 15335169)
		color = 16711680;
	else
		color = 16777215;
	ft_changematrixcol(color, size, ptr);
	ft_dispmatrix(size, ptr);
	ft_context(ptr, color);
}
