/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstaddend.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 11:30:35 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 11:33:58 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **lst, t_list *new)
{
	t_list	*current;

	if (lst != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			current = *lst;
			while (current->next != NULL)
				current = current->next;
			current->next = new;
		}
	}
}
