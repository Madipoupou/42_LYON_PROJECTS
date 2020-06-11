/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error_manager.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/19 11:41:10 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/19 16:46:21 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_error_manager(int err, char *str)
{
	if (err == 21)
	{
		ft_putstr("cat: ", 2);
		ft_putstr(str, 2);
		ft_putstr(": Is a directory\n", 2);
	}
	else if (err == 2)
	{
		ft_putstr("cat: ", 2);
		ft_putstr(str, 2);
		ft_putstr(": No such file or directory\n", 2);
	}
	else if (err == 63)
	{
		ft_putstr("cat: ", 2);
		ft_putstr(str, 2);
		ft_putstr(": File name too long\n", 2);
	}
	else if (err == 13)
	{
		ft_putstr("cat: ", 2);
		ft_putstr(str, 2);
		ft_putstr(": Permission denied\n", 2);
	}
}
