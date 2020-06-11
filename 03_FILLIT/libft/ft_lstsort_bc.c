/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstsort_bc.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:50:22 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 13:55:01 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lstsort_bc(t_list *lst, int (*f)(void *, void *))
{
	t_list	*current;
	t_list	*after;

	if (lst == NULL || lst->next == NULL)
		return ;
	current = lst;
	while (current->next != NULL)
	{
		after = current->next;
		while (after != NULL)
		{
			if ((*f)(current->content, after->content) > 0)
				ft_lstswap_c(current, after);
			after = after->next;
		}
		current = current->next;
	}
}
