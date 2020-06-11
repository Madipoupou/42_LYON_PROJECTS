/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   errors.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 16:18:54 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/27 17:58:14 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int	ft_printusage(void)
{
	ft_putstr("usage:\t");
	ft_putendl("./fillit -filename");
	return (0);
}

int	ft_puterror(void)
{
	ft_putendl("error");
	return (0);
}
