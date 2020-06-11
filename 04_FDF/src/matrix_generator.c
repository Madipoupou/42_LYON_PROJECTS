/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   matrix_generator.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 12:03:26 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/11 17:37:45 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fdf.h"

static void	ft_isocoord(t_list *lst, void **ptr, int *size, int first)
{
	t_list	*cur;
	int		i;
	int		j;
	int		*coord;
	int		***matrix;

	matrix = (int ***)ptr[3];
	cur = lst;
	i = -1;
	while (++i < size[0])
	{
		j = 0;
		while (j < size[1])
		{
			coord = (int *)cur->content;
			matrix[i][j][0] = (int)(ISO_CST1 * coord[0] - ISO_CST2 * coord[1]);
			matrix[i][j][1] = (int)(-1 * coord[2] + (ISO_CST1 / 2) * coord[0] +
					(ISO_CST2 / 2) * coord[1]);
			if (first == 0)
				matrix[i][j][2] = 16777215;
			cur = cur->next;
			j++;
		}
	}
	ptr[3] = (void *)matrix;
}

static int	***ft_initmatrix(int *size)
{
	int	i;
	int	j;
	int	***matrix;

	matrix = (int ***)ft_memalloc(size[0] * sizeof(int **));
	if (matrix == NULL)
		return (NULL);
	i = -1;
	while (++i < size[0])
	{
		matrix[i] = (int **)ft_memalloc(size[1] * sizeof(int *));
		if (matrix[i] == NULL)
			exit(0);
	}
	i = -1;
	while (++i < size[0] && (j = -1))
		while (++j < size[1])
		{
			matrix[i][j] = (int *)ft_memalloc(3 * sizeof(int));
			if (matrix[i][j] == NULL)
				exit(0);
		}
	return (matrix);
}

void		ft_isomatrix(void **ptr, int first)
{
	int		*size;
	t_list	*lst;

	size = (int *)ptr[5];
	lst = (t_list *)ptr[2];
	if (ptr[3] == NULL)
		ptr[3] = (void *)ft_initmatrix(size);
	if (ptr[3] == NULL)
		return ;
	ft_isocoord(lst, ptr, size, first);
}
