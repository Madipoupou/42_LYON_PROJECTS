/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_reverse.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/18 14:54:50 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 17:12:52 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*current;
	t_list	*next_one;
	t_list	*prev;

	if (*begin_list == 0 || (*begin_list)->next == 0)
		return ;
	prev = 0;
	current = *begin_list;
	while (current != 0)
	{
		next_one = current->next;
		current->next = prev;
		prev = current;
		current = next_one;
	}
	*begin_list = prev;
}
