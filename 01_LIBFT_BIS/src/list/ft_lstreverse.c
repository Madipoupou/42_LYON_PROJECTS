/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstreverse.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 12:11:24 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 13:05:34 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreverse(t_list **lst)
{
	t_list	*cur;
	t_list	*prev;
	t_list	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	prev = NULL;
	cur = *lst;
	next = (*lst)->next;
	while (next != NULL)
	{
		cur->next = prev;
		prev = cur;
		cur = next;
		next = next->next;
	}
	cur->next = prev;
	*lst = cur;
}
