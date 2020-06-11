/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_foreach_if.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/18 18:19:44 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 18:30:01 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list,
		void (*f)(void *),
		void *data_ref,
		int (*cmp)())
{
	t_list	*current;

	current = begin_list;
	while (current != 0)
	{
		if ((*cmp)(current->data, data_ref) == 0)
			(*f)(current->data);
		current = current->next;
	}
}
