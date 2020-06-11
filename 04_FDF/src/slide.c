/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   slide.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 17:12:13 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/11 22:59:38 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fdf.h"

static void	ft_coordslide(t_list *lst, int x, int y)
{
	t_list	*cur;
	int		*coord;

	cur = lst;
	while (cur != NULL)
	{
		coord = (int *)cur->content;
		coord[0] += x;
		coord[1] += y;
		cur = cur->next;
	}
}

void		ft_slide(int key, void **ptr)
{
	t_list	*lst;

	lst = (t_list *)ptr[2];
	if (key == 126)
		ft_coordslide(lst, -50, -50);
	else if (key == 125)
		ft_coordslide(lst, 50, 50);
	else if (key == 123)
		ft_coordslide(lst, -50, 50);
	else
		ft_coordslide(lst, 50, -50);
	ft_isomatrix(ptr, 1);
	ft_dispmatrix((int *)ptr[5], ptr);
}
