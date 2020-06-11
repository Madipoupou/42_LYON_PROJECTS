/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fill_list.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/22 11:47:34 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 16:56:28 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/my2.h"

int	ft_fill_list(t_list **begin, int *tot_char)
{
	int		cpt_line;
	char	c;
	t_list	*current;

	cpt_line = 0;
	while (read(0, &c, 1))
	{
		if (*tot_char == 0)
		{
			*begin = ft_create_elem(c);
			current = *begin;
		}
		else
		{
			current->next = ft_create_elem(c);
			current = current->next;
		}
		if (c == '\n')
			cpt_line++;
		else
			*tot_char = *tot_char + 1;
	}
	if (*begin != 0)
		current->next = ft_create_elem('\n');
	return (cpt_line);
}
