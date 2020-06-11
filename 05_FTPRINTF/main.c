/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 14:11:21 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/28 15:58:26 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <fcntl.h>

int	main(void)
{
	double	f;

	f = 1.42;
	ft_printf("%.3lf\n", f);
	printf("%.3lf\n", f);
}
