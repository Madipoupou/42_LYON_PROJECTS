/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 16:13:23 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/27 18:18:20 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		check;
	t_list	*lst;
	char	**grid;

	if (argc != 2)
		return (ft_printusage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_puterror());
	lst = NULL;
	check = ft_readfile(fd, &lst);
	close(fd);
	if (check == 0)
	{
		ft_lstdel(&lst, &ft_lstdelshape);
		return (ft_puterror());
	}
	grid = ft_solve(lst);
	ft_lstdel(&lst, &ft_lstdelshape);
	ft_display(grid);
	ft_strtabdel(grid);
	free(grid);
	return (0);
}
