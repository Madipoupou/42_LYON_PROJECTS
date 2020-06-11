/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   context.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 16:45:35 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 01:42:05 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fdf.h"

static void	ft_sidelines(void **ptr, int color)
{
	size_t	i;
	size_t	j;

	i = 245;
	while (i < 250)
	{
		j = 0;
		while (j < 1300)
		{
			mlx_pixel_put(ptr[0], ptr[1], i, j, color);
			j++;
		}
		i++;
	}
	i = 2361;
	while (i <= 2366)
	{
		j = 0;
		while (j < 1300)
		{
			mlx_pixel_put(ptr[0], ptr[1], i, j, color);
			j++;
		}
		i++;
	}
}

static void	ft_header_footer(void **ptr, int color)
{
	size_t	i;
	size_t	j;

	i = 249;
	while (i < 2361)
	{
		j = 95;
		while (j < 100)
		{
			mlx_pixel_put(ptr[0], ptr[1], i, j, color);
			j++;
		}
		i++;
	}
	i = 245;
	while (i < 2367)
	{
		j = 1349;
		while (j > 1299)
		{
			mlx_pixel_put(ptr[0], ptr[1], i, j, color);
			j--;
		}
		i++;
	}
}

static void	ft_write_header_footer(void **ptr, int color)
{
	size_t	i;
	size_t	j;

	i = 1000;
	while (i < 2000)
	{
		j = 35;
		while (j < 80)
		{
			mlx_pixel_put(ptr[0], ptr[1], i, j, 0);
			j++;
		}
		i++;
	}
	mlx_string_put(ptr[0], ptr[1], 1140, 40, color,
			"FDF - Wireframe map displayer");
	mlx_string_put(ptr[0], ptr[1], 2150, 1315, 0, "2018 - 101 project");
}

static void	ft_instructions(void **ptr, int color)
{
	size_t	i;
	size_t	j;

	i = 9;
	while (++i < 189)
	{
		j = 114;
		while (++j < 1295)
			mlx_pixel_put(ptr[0], ptr[1], i, j, 0);
	}
	mlx_string_put(ptr[0], ptr[1], 10, 250, color, "COMMANDS:");
	mlx_string_put(ptr[0], ptr[1], 10, 300, color, "- Up : slide up");
	mlx_string_put(ptr[0], ptr[1], 10, 325, color, "- Down : slide down");
	mlx_string_put(ptr[0], ptr[1], 10, 350, color, "- Left : slide left");
	mlx_string_put(ptr[0], ptr[1], 10, 375, color, "- Right : slide right");
	mlx_string_put(ptr[0], ptr[1], 10, 450, color, "- x : X rotation");
	mlx_string_put(ptr[0], ptr[1], 10, 475, color, "- y : Y rotation");
	mlx_string_put(ptr[0], ptr[1], 10, 500, color, "- z : Z rotation");
	mlx_string_put(ptr[0], ptr[1], 10, 575, color, "- R-Clic : Zoom in");
	mlx_string_put(ptr[0], ptr[1], 10, 600, color, "- L-Clic : Zoom out");
	mlx_string_put(ptr[0], ptr[1], 10, 675, color, "- Num +: Inc. height");
	mlx_string_put(ptr[0], ptr[1], 10, 700, color, "- Num -: Dec. height");
	mlx_string_put(ptr[0], ptr[1], 10, 775, color, "- c: Color changer");
	mlx_string_put(ptr[0], ptr[1], 10, 850, color, "Press ESC to quit...");
}

void		ft_context(void **ptr, int color)
{
	ft_header_footer(ptr, color);
	ft_sidelines(ptr, color);
	ft_instructions(ptr, color);
	ft_write_header_footer(ptr, color);
}
