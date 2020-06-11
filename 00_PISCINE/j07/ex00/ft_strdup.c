/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/11 21:44:28 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/11 22:15:00 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*copy;
	int		len;
	int		i;

	len = 0;
	while (*(src + len))
		len++;
	copy = (char*)malloc(sizeof(copy) * (len + 1));
	if (!copy)
		return (0);
	i = 0;
	while (i < len)
	{
		*(copy + i) = *(src + i);
		i++;
	}
	*(copy + i) = '\0';
	return (copy);
}
