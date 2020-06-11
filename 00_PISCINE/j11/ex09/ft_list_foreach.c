/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_foreach.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/18 17:15:31 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 18:18:15 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*current;

	current = begin_list;
	while (current != 0)
	{
		(*f)(current->data);
		current = current->next;
	}
}
