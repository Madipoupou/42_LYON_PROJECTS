/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_remove_if.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/18 20:11:46 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 20:50:22 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*prev;
	t_list	*next_one;
	t_list	*current;

	if (*begin_list == 0)
		return ;
	current = *begin_list;
	prev = 0;
	while (current != 0)
	{
		next_one = current->next;
		if ((*cmp)(current->data, data_ref) == 0)
		{
			if (prev != 0)
				prev->next = next_one;
			else
				*begin_list = next_one;
			free(current);
		}
		else
			prev = current;
		current = current->next;
	}
}
