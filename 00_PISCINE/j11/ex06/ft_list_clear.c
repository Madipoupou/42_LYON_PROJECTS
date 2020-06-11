/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_clear.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/18 13:58:10 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 14:24:44 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list **begin_list)
{
	t_list	*current;
	t_list	*before;

	if (*begin_list == NULL)
		return ;
	current = *begin_list;
	while (current->next != NULL)
	{
		before = current;
		current = current->next;
		free(before);
	}
	free(current);
	*begin_list = NULL;
}
