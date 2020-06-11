/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/30 22:37:50 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 15:26:35 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void	ft_yellow(t_bag *ptr)
{
	ptr->col.range = 5;
	ptr->col.color[0] = 0xFFFDE7;
	ptr->col.color[1] = 0xFFF9C4;
	ptr->col.color[2] = 0xFFF59D;
	ptr->col.color[3] = 0xFFF176;
	ptr->col.color[4] = 0xFFEE58;
	ptr->col.color[5] = 0xFFEB3B;
	ptr->col.color[6] = 0xFDD835;
	ptr->col.color[7] = 0xFFFF8D;
	ptr->col.color[8] = 0xFFEA00;
	ptr->col.color[9] = 0xFFD600;
	ptr->col.color[10] = 0xFFFF00;
}

void	ft_teal(t_bag *ptr)
{
	ptr->col.range = 6;
	ptr->col.color[0] = 0xFFFFFF;
	ptr->col.color[1] = 0xE0F2F1;
	ptr->col.color[2] = 0xB2DFDB;
	ptr->col.color[3] = 0x80CBC4;
	ptr->col.color[4] = 0x4DB6AC;
	ptr->col.color[5] = 0x26A69A;
	ptr->col.color[6] = 0x008688;
	ptr->col.color[7] = 0x00897B;
	ptr->col.color[8] = 0x00796B;
	ptr->col.color[9] = 0x00695C;
	ptr->col.color[10] = 0x004D40;
}

int		ft_colormg_reverse(t_bag *ptr_bag)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 10;
	while (j > i)
	{
		temp = ptr_bag->col.color[i];
		ptr_bag->col.color[i] = ptr_bag->col.color[j];
		ptr_bag->col.color[j] = temp;
		i++;
		j--;
	}
	return (0);
}

int		ft_colormg(t_bag *ptr_bag)
{
	int	temp;

	if (ptr_bag->col.mode == 1)
	{
		temp = ptr_bag->col.range;
		if (temp == 0)
			ft_lblue(ptr_bag);
		else if (temp == 1)
			ft_lgreen(ptr_bag);
		else if (temp == 2)
			ft_red(ptr_bag);
		else if (temp == 3)
			ft_brown(ptr_bag);
		else if (temp == 4)
			ft_yellow(ptr_bag);
		else if (temp == 5)
			ft_teal(ptr_bag);
		else
			ft_initcol(ptr_bag);
		ft_info_color(ptr_bag);
	}
	else
		ptr_bag->col.random = (rand() + 100) % 0xFFFFFF;
	return (0);
}
