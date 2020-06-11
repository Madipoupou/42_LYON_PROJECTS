/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sorted_list_insert.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/18 22:56:12 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 23:06:12 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back2(t_list **begin_list, int x)
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

void	ft_list_sort2(t_list **begin_list)
{
	t_list	*current;
	t_list	*next_one;
	int		temp;

	if (*begin_list == 0)
		return ;
	current = *begin_list;
	while (current->next != 0)
	{
		next_one = current->next;
		while (next_one != 0)
		{
			if (current->x > next_one->x)
			{
				temp = current->x;
				current->x = next_one->x;
				next_one->x = temp;
			}
			next_one = next_one->next;
		}
		current = current->next;
	}
}

void	ft_sorted_list_insert(t_list **begin_list, int x)
{
	ft_list_push_back2(begin_list, x);
	ft_list_sort2(begin_list);
}
