/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_reverse_fun.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/18 22:26:50 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 22:53:27 by mhotting    ###    #+. /#+    ###.fr     */
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

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*last;
	t_list	*temp_end;
	void	*temp;

	if (begin_list == 0)
		return ;
	last = begin_list;
	while (last->next != 0)
	{
		temp_end = last;
		last = last->next;
	}
	temp = begin_list->data;
	begin_list->data = last->data;
	last->data = temp;
	temp_end->next = 0;
	ft_list_reverse(&(begin_list->next));
	temp_end = begin_list;
	while (temp_end->next != 0)
		temp_end = temp_end->next;
	temp_end->next = last;
}
