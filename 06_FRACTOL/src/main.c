/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 18:54:47 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 14:18:17 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"

static void	ft_init_mlx(void *ptr, int choice)
{
	t_bag	*ptr_bag;

	ptr_bag = (t_bag *)ptr;
	ptr_bag->mlx = mlx_init();
	ptr_bag->win = mlx_new_window(ptr_bag->mlx,
			WIN_L, WIN_H, "FRACTOL: A WAY TO INFINITY");
	ptr_bag->img_ptr = NULL;
	ptr_bag->choice = choice;
	ptr_bag->move_value = 0.10;
	mlx_key_hook(ptr_bag->win, &ft_keymg, ptr);
	mlx_hook(ptr_bag->win, 6, 0, &ft_motionmg, ptr);
	mlx_hook(ptr_bag->win, 4, (1L << 2), &ft_bpress, ptr);
	mlx_hook(ptr_bag->win, 5, (1L << 3), &ft_brelease, ptr);
	if ((choice >= 1 && choice <= 4) || choice == 6 || choice == 7)
	{
		ptr_bag->ft_init = &ft_initmand;
		ptr_bag->ft_frac = &ft_mandelbrot;
	}
	else if (choice == 5 || (choice >= 8 && choice <= 9))
	{
		ptr_bag->ft_init = &ft_initjulia;
		ptr_bag->ft_frac = &ft_julia;
	}
	ft_context(ptr, 0xFFFFFF);
	ft_initcol(ptr_bag);
}

int			main(int ac, char **av)
{
	int		choice;
	t_bag	bag;
	void	*ptr_bag;

	if (ac != 2)
		return (ft_usage());
	choice = ft_atoi(av[1]);
	if (choice < 1 || choice > TOT_FRAC)
		return (ft_puterror("ERROR - Bad argument\n"));
	srand(time(NULL));
	ptr_bag = (void *)&bag;
	ft_init_mlx(ptr_bag, choice);
	(bag.ft_init)((t_bag *)ptr_bag);
	ft_info_panel(ptr_bag);
	ft_sync_frac(ptr_bag);
	mlx_loop(bag.mlx);
	return (0);
}
