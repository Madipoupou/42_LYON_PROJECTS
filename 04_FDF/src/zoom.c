/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   zoom.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 18:37:05 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/11 17:38:08 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fdf.h"

static void	ft_applyzoom(t_list *lst, int sign)
{
	int			*coord;
	t_list		*cur;
	static int	zoomed = 0;

	cur = lst;
	while (cur != NULL)
	{
		coord = (int *)cur->content;
		if (sign > 0)
		{
			coord[0] = coord[0] * 2 - 1700;
			coord[1] = coord[1] * 2;
			coord[2] *= 2;
			zoomed++;
		}
		else if (zoomed > 0)
		{
			coord[0] = coord[0] / 2 + 850;
			coord[1] /= 2;
			coord[2] /= 2;
			zoomed--;
		}
		cur = cur->next;
	}
}

void		ft_zoom(int mouse, void **ptr)
{
	t_list	*lst;

	lst = (t_list *)ptr[2];
	if (mouse == 1)
		ft_applyzoom(lst, -1);
	else
		ft_applyzoom(lst, 1);
	ft_isomatrix(ptr, 1);
	ft_dispmatrix((int *)ptr[5], ptr);
}
