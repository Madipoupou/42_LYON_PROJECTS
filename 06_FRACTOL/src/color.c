/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 10:50:05 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/30 22:38:29 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void	ft_initcol(t_bag *ptr)
{
	ptr->col.mode = 1;
	ptr->col.range = 0;
	ptr->col.random = 0xFFFFFF;
	ptr->col.color[10] = 0;
	ptr->col.color[9] = 0x222222;
	ptr->col.color[8] = 0x444444;
	ptr->col.color[7] = 0x666666;
	ptr->col.color[6] = 0x888888;
	ptr->col.color[5] = 0xAAAAAA;
	ptr->col.color[4] = 0xBBBBBB;
	ptr->col.color[3] = 0xCCCCCC;
	ptr->col.color[2] = 0xDDDDDD;
	ptr->col.color[1] = 0xEEEEEE;
	ptr->col.color[0] = 0xFFFFFF;
}

void	ft_lblue(t_bag *ptr)
{
	ptr->col.range = 1;
	ptr->col.color[0] = 0xE1F5FE;
	ptr->col.color[1] = 0xB3E5FC;
	ptr->col.color[2] = 0x81D4FA;
	ptr->col.color[3] = 0x4FC3F7;
	ptr->col.color[4] = 0x29B6F6;
	ptr->col.color[5] = 0x03A9F4;
	ptr->col.color[6] = 0x039BE5;
	ptr->col.color[7] = 0x0288D1;
	ptr->col.color[8] = 0x0277BD;
	ptr->col.color[9] = 0x40C4FF;
	ptr->col.color[10] = 0x01579B;
}

void	ft_lgreen(t_bag *ptr)
{
	ptr->col.range = 2;
	ptr->col.color[0] = 0xF1F8E9;
	ptr->col.color[1] = 0xDCEDC8;
	ptr->col.color[2] = 0xC5E1A5;
	ptr->col.color[3] = 0xAED581;
	ptr->col.color[4] = 0x9CCC65;
	ptr->col.color[5] = 0x8BC34A;
	ptr->col.color[6] = 0x7CB342;
	ptr->col.color[7] = 0x689F38;
	ptr->col.color[8] = 0x558B2F;
	ptr->col.color[9] = 0x64DD17;
	ptr->col.color[10] = 0x33691E;
}

void	ft_red(t_bag *ptr)
{
	ptr->col.range = 3;
	ptr->col.color[0] = 0xFFEBEE;
	ptr->col.color[1] = 0xFFCDD2;
	ptr->col.color[2] = 0xEF9A9A;
	ptr->col.color[3] = 0xE57373;
	ptr->col.color[4] = 0xEF5350;
	ptr->col.color[5] = 0xF44336;
	ptr->col.color[6] = 0xE53935;
	ptr->col.color[7] = 0xD32F2F;
	ptr->col.color[8] = 0xC62828;
	ptr->col.color[9] = 0xD50000;
	ptr->col.color[10] = 0xB71C1C;
}

void	ft_brown(t_bag *ptr)
{
	ptr->col.range = 4;
	ptr->col.color[0] = 0xFFFFFF;
	ptr->col.color[1] = 0xEFEBE9;
	ptr->col.color[2] = 0xD7CCC8;
	ptr->col.color[3] = 0xBCAAA4;
	ptr->col.color[4] = 0xA1887F;
	ptr->col.color[5] = 0x8D6E63;
	ptr->col.color[6] = 0x795548;
	ptr->col.color[7] = 0x6D4C41;
	ptr->col.color[8] = 0x5D4037;
	ptr->col.color[9] = 0x4E342E;
	ptr->col.color[10] = 0x3E2723;
}
