/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_linelen.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/15 20:31:23 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/15 20:47:45 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_sudoku.h"

t_bool	ft_check_linelen(char **argv)
{
	int i;

	i = 1;
	while (i <= SIZE)
	{
		if (ft_strlen(argv[i]) != SIZE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
