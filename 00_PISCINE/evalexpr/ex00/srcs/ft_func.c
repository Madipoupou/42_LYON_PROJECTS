/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_func.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/22 22:12:48 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 22:18:07 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_h.h"

int	ft_count_op(char *str)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*')
			cpt++;
		else if (str[i] == '/' || str[i] == '%')
			cpt++;
		i++;
	}
	return (cpt);
}

int	ft_is_operator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return (1);
	return (0);
}
