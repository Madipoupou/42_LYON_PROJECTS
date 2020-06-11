/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/20 09:04:20 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/20 09:19:05 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;
	int		rc;
	char	*str;

	rc = ac;
	if (ac != 2)
	{
		printf("Error - Number of argument(s) is not correct\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	while ((rc = get_next_line(fd, &str)) == 1)
	{
		if (str == NULL)
		{
			printf("Error - Returned pointer is NULL\n");
			break ;
		}
		printf("MAIN:\t%s\n", str);
		free(str);
	}
	if (rc == -1)
		printf("Error - The file cannot be read\n");
	close(fd);
	return (0);
}
