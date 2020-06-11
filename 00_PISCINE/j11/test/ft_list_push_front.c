/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_push_front.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 18:25:55 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 18:46:02 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, int x)
{
	t_list	*temp;

	temp = ft_create_elem(x);
	if (*begin_list == 0)
		*begin_list = temp;
	else
	{
		temp->next = *begin_list;
		*begin_list = temp;
	}
}
