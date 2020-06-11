/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 10:53:33 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 11:20:56 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"

/*
** Clear a list (fully)
** Possible to do it using recursivity
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	if (alst != NULL && *alst != NULL && del != NULL)
	{
		while (*alst != NULL)
		{
			next = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = next;
		}
	}
}
