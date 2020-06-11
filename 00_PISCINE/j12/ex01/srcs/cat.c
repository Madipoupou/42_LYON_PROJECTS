/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/19 01:39:12 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/19 16:46:11 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/ft.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		i;

	if (argc == 1)
		ft_infinity_loop();
	else
	{
		i = 0;
		while (++i < argc)
		{
			if ((fd = open(argv[i], O_RDWR) == -1))
				ft_error_manager(errno, argv[i]);
			else
			{
				ft_readfile(fd);
				if ((fd = close(fd)) == -1)
					ft_putstr("Error - closing file error.\n", 2);
			}
		}
	}
	return (0);
}
