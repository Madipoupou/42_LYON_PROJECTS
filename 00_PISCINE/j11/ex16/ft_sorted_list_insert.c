/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sorted_list_insert.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/18 22:56:12 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 23:07:10 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*temp;
	t_list	*current;

	temp = ft_create_elem(data);
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

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	ft_list_push_back(begin_list, data);
	ft_list_sort(begin_list, cmp);
}
