/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_sort.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/18 21:13:23 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 22:22:03 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_sort(t_list **begin_list)
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
