/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 11:39:12 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 13:03:40 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*current;
	t_list	*temp;

	new_lst = NULL;
	if (lst != NULL && f != NULL)
	{
		temp = (*f)(lst);
		new_lst = ft_lstnew(temp->content, temp->content_size);
		if (new_lst == NULL)
			return (NULL);
		lst = lst->next;
		current = new_lst;
		while (lst != NULL)
		{
			temp = (*f)(lst);
			current->next = ft_lstnew(temp->content, temp->content_size);
			current = current->next;
			if (current == NULL)
				return (NULL);
			lst = lst->next;
		}
	}
	return (new_lst);
}
