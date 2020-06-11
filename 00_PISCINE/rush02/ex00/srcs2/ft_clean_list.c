/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_clean_list.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/22 13:29:43 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 13:31:44 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/my2.h"

void	ft_clean_list(t_list *begin)
{
	t_list	*current;
	t_list	*prev;

	if (begin == NULL)
		return ;
	current = begin;
	while (current != NULL)
	{
		prev = current;
		current = current->next;
		free(prev);
	}
}
