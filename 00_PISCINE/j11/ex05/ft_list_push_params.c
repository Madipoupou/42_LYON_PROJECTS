/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_push_params.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 20:01:17 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 20:51:36 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*temp;

	temp = ft_create_elem(data);
	if (*begin_list == 0)
		*begin_list = temp;
	else
	{
		temp->next = *begin_list;
		*begin_list = temp;
	}
}

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*my_list;
	int		i;

	my_list = 0;
	if (ac <= 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		ft_list_push_front(&my_list, av[i]);
		i++;
	}
	return (my_list);
}
