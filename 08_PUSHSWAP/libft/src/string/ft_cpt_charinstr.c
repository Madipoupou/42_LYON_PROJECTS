/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cpt_charinstr.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 15:06:12 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 15:25:28 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"

int	ft_cpt_charinstr(char c, char *str)
{
	size_t	i;
	int		cpt;

	cpt = 0;
	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			cpt++;
		i++;
	}
	return (cpt);
}
