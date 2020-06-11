/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/19 16:52:52 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/19 16:56:44 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft.h"

void	error(char *str_file)
{
	ft_putstr("tail: ", 2);
	ft_putstr(str_file, 2);
	ft_putstr(" : No such file or directory\n", 2);
}
