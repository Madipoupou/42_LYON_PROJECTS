/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event_manager.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 18:20:58 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 00:27:23 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_cleanmem(void **ptr)
{
	int		***matrix;
	t_list	*lst;
	int		*size;
	int		i;
	int		j;

	matrix = (int ***)ptr[3];
	lst = (t_list *)ptr[2];
	size = (int *)ptr[5];
	if (ptr[1] != NULL)
		mlx_destroy_window(ptr[0], ptr[1]);
	if (ptr[4] != NULL)
		mlx_destroy_image(ptr[0], ptr[4]);
	free(ptr[0]);
	ft_lstdel(&lst, &ft_lstintdel);
	i = -1;
	while (++i < size[0] && (j = -1))
	{
		while (++j < size[1])
			free(matrix[i][j]);
		free(matrix[i]);
	}
	free(matrix);
}

int			ft_keymanager(int key, void *param)
{
	void	**ptr;

	ptr = (void **)param;
	if (key == 7 || key == 16 || key == 6)
		ft_rotate(key, ptr);
	if (key == 53)
	{
		ft_cleanmem(ptr);
		exit(0);
	}
	if (key >= 123 && key <= 126)
		ft_slide(key, ptr);
	if (key == 69 || key == 78)
		ft_editheight(key, ptr);
	if (key == 8)
		ft_changecolor(ptr);
	return (0);
}

int			ft_mousemanager(int mouse, int x, int y, void *param)
{
	void	**ptr;

	x = y;
	ptr = (void **)param;
	if (mouse == 1 || mouse == 2)
		ft_zoom(mouse, ptr);
	return (0);
}
