/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_at.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/18 14:28:27 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 14:49:07 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*current;

	if (begin_list == 0)
		return (0);
	if (nbr == 0)
		return (begin_list);
	i = 0;
	current = begin_list;
	while (current->next != 0)
	{
		current = current->next;
		i++;
		if (i == nbr)
			return (current);
	}
	return (0);
}
