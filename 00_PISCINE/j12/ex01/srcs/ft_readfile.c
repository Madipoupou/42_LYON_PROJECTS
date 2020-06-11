/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_readfile.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/19 03:32:41 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/19 04:10:39 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/ft.h"

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr(char *str, int fd)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], fd);
		i++;
	}
}

void	ft_readfile(int fd)
{
	char	str[BUF_SIZE + 1];
	int		cpt;

	while ((cpt = read(fd, str, BUF_SIZE)))
	{
		str[cpt] = '\0';
		ft_putstr(str, 1);
	}
}
