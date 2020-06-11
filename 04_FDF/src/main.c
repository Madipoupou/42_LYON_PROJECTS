/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/27 20:08:20 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 19:18:12 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*lst;
	int		ok;
	int		size[3];

	if (argc != 2)
		return (ft_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_puterror("ERROR - File cannot be read\n"));
	lst = NULL;
	if ((ok = ft_parse(fd, &lst, size)) == 0)
	{
		ft_lstdel(&lst, &ft_lstintdel);
		ft_puterror("ERROR - Impossible to extract data from file\n");
	}
	ft_updatecoord(lst, size[0], size[1], size[2]);
	ft_display(lst, size);
	return (0);
}
