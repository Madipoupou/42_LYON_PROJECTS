/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_size.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 19:44:06 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 19:50:29 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		cpt;
	t_list	*current;

	cpt = 0;
	current = begin_list;
	while (current != 0)
	{
		current = current->next;
		cpt++;
	}
	return (cpt);
}
