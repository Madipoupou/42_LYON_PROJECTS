/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rotate.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 20:27:43 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/11 23:52:49 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fdf.h"

static void	ft_rotx(void **ptr)
{
	t_list	*lst;
	int		*coord;
	int		tmp1;
	int		tmp2;

	lst = (t_list *)ptr[2];
	while (lst != NULL)
	{
		coord = (int *)lst->content;
		tmp1 = coord[1];
		tmp2 = coord[2];
		coord[1] = (int)(tmp1 * cos(3.141592 / 4) - tmp2 * sin(3.141592 / 4));
		coord[2] = (int)(tmp1 * sin(3.141592 / 4) + tmp2 * cos(3.141592 / 4));
		lst = lst->next;
	}
}

static void	ft_roty(void **ptr)
{
	t_list	*lst;
	int		*coord;
	int		tmp1;
	int		tmp2;

	lst = (t_list *)ptr[2];
	while (lst != NULL)
	{
		coord = (int *)lst->content;
		tmp1 = coord[0];
		tmp2 = coord[2];
		coord[0] = (int)(tmp1 * cos(3.141592 / 4) +
				tmp2 * sin(3.141592 / 4)) + 500;
		coord[2] = (int)(-1 * tmp1 * sin(3.141592 / 4) +
				tmp2 * cos(3.141592 / 4)) + 1000;
		lst = lst->next;
	}
}

static void	ft_rotz(void **ptr)
{
	t_list	*lst;
	int		*coord;
	int		tmp1;
	int		tmp2;

	lst = (t_list *)ptr[2];
	while (lst != NULL)
	{
		coord = (int *)lst->content;
		tmp1 = coord[0];
		tmp2 = coord[1];
		coord[0] = (int)(tmp1 * cos(3.141592 / 4) -
				tmp2 * sin(3.141592 / 4)) + 200;
		coord[1] = (int)(tmp1 * sin(3.141592 / 4) +
				tmp2 * cos(3.141592 / 4)) - 1000;
		lst = lst->next;
	}
}

void		ft_rotate(int key, void **ptr)
{
	if (key == 7)
		ft_rotx(ptr);
	else if (key == 16)
		ft_roty(ptr);
	else
		ft_rotz(ptr);
	ft_isomatrix(ptr, 1);
	ft_dispmatrix((int *)ptr[5], ptr);
}
