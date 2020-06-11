/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 17:00:38 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 01:35:24 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_dispmatrix(int *size, void **ptr)
{
	int		i;
	int		j;
	char	*str_img;
	int		d[3];
	int		***matrix;

	matrix = (int ***)ptr[3];
	if (ptr[4] != NULL)
		mlx_destroy_image(ptr[0], ptr[4]);
	ptr[4] = mlx_new_image(ptr[0], 2110, 1200);
	str_img = mlx_get_data_addr(ptr[4], d, d + 1, d + 2);
	i = -1;
	while (++i < size[0] && (j = -1))
	{
		while (++j < size[1])
		{
			if (i < size[0] - 1)
				ft_drawline(matrix[i][j], matrix[i + 1][j], str_img,
						matrix[i][j][2]);
			if (j < size[1] - 1)
				ft_drawline(matrix[i][j], matrix[i][j + 1], str_img,
						matrix[i][j][2]);
		}
	}
	mlx_put_image_to_window(ptr[0], ptr[1], ptr[4], 250, 100);
}

void		ft_display(t_list *lst, int *size)
{
	void	*ptr[6];

	ptr[0] = mlx_init();
	ptr[1] = mlx_new_window(ptr[0], 2560, 1350, "F.D.F -> Fans Domifile Fixe");
	ptr[2] = (void *)lst;
	ptr[3] = NULL;
	ptr[5] = (void *)size;
	ft_isomatrix(ptr, 0);
	ptr[4] = NULL;
	ft_dispmatrix(size, ptr);
	mlx_mouse_hook(ptr[1], &ft_mousemanager, ptr);
	mlx_key_hook(ptr[1], &ft_keymanager, ptr);
	ft_context(ptr, 16777215);
	mlx_loop(ptr[0]);
}
