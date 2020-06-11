/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 21:10:06 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 15:51:33 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static const char *g_col1[NB_COLOR] =
{
	"{none}",
	"{blue}",
	"{bold}",
	"{black}",
	"{red}",
	"{green}",
	"{brown}",
	"{magenta}",
	"{cyan}",
	"{gray}",
	"{yellow}"
};

static const char *g_col2[NB_COLOR] =
{
	C_NONE,
	C_BLUE,
	C_BOLD,
	C_BLACK,
	C_RED,
	C_GREEN,
	C_BROWN,
	C_MAGENTA,
	C_CYAN,
	C_GRAY,
	C_YELLOW
};

static int	ft_color_checker(const char *format)
{
	int	i;

	i = 0;
	while (i < NB_COLOR)
	{
		if (ft_strcmp(g_col1[i], (char *)format) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int			ft_color_manager(const char *format)
{
	int	res;

	res = ft_color_checker(format);
	if (res != -1)
	{
		ft_putstr(g_col2[res]);
		return (1);
	}
	return (0);
}
