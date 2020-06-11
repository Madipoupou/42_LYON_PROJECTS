/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_sort.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/18 21:13:23 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 22:24:17 by mhotting    ###    #+. /#+    ###.fr     */
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
