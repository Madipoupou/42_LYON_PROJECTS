/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_merge.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/18 20:51:35 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 21:03:26 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*current;

	if (*begin_list1 == 0)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	current = *begin_list1;
	while (current->next != 0)
		current = current->next;
	current->next = begin_list2;
}
