/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 14:46:40 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 01:29:26 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_usage(void)
{
	ft_putendl("usage:\t./fdf source_file");
	return (0);
}

int	ft_puterror(char *str)
{
	ft_putstr(str);
	return (0);
}
