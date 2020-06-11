/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/19 01:39:12 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/19 16:18:54 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/ft.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
	{
		ft_putstr("File name missing.\n", 2);
		return (0);
	}
	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n", 2);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error - The file can't be read.\n", 2);
		return (0);
	}
	ft_readfile(fd);
	fd = close(fd);
	if (fd == -1)
		ft_putstr("Error - closing file error.\n", 2);
	return (0);
}
