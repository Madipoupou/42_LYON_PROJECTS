/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_remove_ws.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/22 22:21:23 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 22:26:56 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_h.h"

char	*ft_remove_ws(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!res)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			res[j] = str[i];
			j++;
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}
