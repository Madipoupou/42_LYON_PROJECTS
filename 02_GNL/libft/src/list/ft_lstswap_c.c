/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstswap_c.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:46:32 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 13:49:18 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"

void	ft_lstswap_c(t_list *m1, t_list *m2)
{
	void	*temp1;
	size_t	temp2;

	temp1 = m1->content;
	temp2 = m1->content_size;
	m1->content = m2->content;
	m1->content_size = m2->content_size;
	m2->content = temp1;
	m2->content_size = temp2;
}
