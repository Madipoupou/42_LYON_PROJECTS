/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sorted_list_merge.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/18 23:09:20 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 23:13:29 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	t_list	*next_one;
	void	*temp;

	if (*begin_list == 0)
		return ;
	current = *begin_list;
	while (current->next != 0)
	{
		next_one = current->next;
		while (next_one != 0)
		{
			if ((*cmp)(current->data, next_one->data) > 0)
			{
				temp = current->data;
				current->data = next_one->data;
				next_one->data = temp;
			}
			next_one = next_one->next;
		}
		current = current->next;
	}
}

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

void	ft_sorted_list_merge(t_list **begin_list1,
		t_list *begin_list2,
		int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}
