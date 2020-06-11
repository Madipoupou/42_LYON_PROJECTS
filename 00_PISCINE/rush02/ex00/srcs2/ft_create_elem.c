/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_create_elem.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/22 11:41:32 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 11:42:53 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/my2.h"

t_list	*ft_create_elem(char c)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->c = c;
	new->next = NULL;
	return (new);
}
