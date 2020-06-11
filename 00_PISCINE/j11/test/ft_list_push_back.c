/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_push_back.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 17:08:53 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 18:45:32 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./ft_list.h"

void	ft_list_push_back(t_list **begin_list, int x)
{
	t_list	*temp;
	t_list	*current;

	temp = ft_create_elem(x);
	if (*begin_list == 0)
		*begin_list = temp;
	else
	{
		current = *begin_list;
		while (current->next != 0)
			current = current->next;
		current->next = temp;
	}
}
