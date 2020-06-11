/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   height.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 12:11:29 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/11 17:36:32 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fdf.h"

static void	ft_height(t_list *lst, int h)
{
	int			*coord;
	static int	up = 0;

	while (lst != NULL)
	{
		coord = (int *)lst->content;
		if (h > 0)
		{
			if (coord[2] > 0)
				coord[2] += h;
			else if (coord[2] < 0)
				coord[2] -= h;
			up++;
		}
		else if (h < 0 && up > 0)
		{
			if (coord[2] > 0)
				coord[2] += h;
			else if (coord[2] < 0)
				coord[2] -= h;
			up--;
		}
		lst = lst->next;
	}
}

void		ft_editheight(int key, void **ptr)
{
	t_list	*lst;

	lst = (t_list *)ptr[2];
	if (key == 69)
		ft_height(lst, 10);
	else
		ft_height(lst, -10);
	ft_isomatrix(ptr, 1);
	ft_dispmatrix((int *)ptr[5], ptr);
}
