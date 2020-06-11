/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstremove.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 14:18:55 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 14:29:26 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lstremove(t_list **lst, t_list **rem, void (*del)(void *, size_t))
{
	t_list	*cur;
	t_list	*before;

	if (!lst || !(*lst) || !rem || !(*rem) || !del)
		return ;
	if (*lst == *rem)
	{
		*lst = (*lst)->next;
		ft_lstdelone(rem, del);
		return ;
	}
	before = *lst;
	cur = (*lst)->next;
	while (cur != NULL && cur != *rem)
	{
		before = cur;
		cur = cur->next;
	}
	if (!cur)
		return ;
	before->next = cur->next;
	ft_lstdelone(rem, del);
}
