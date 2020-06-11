/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_last.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 19:52:14 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 19:54:25 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*current;

	current = begin_list;
	if (!current)
		return (0);
	while (current->next != 0)
		current = current->next;
	return (current);
}
