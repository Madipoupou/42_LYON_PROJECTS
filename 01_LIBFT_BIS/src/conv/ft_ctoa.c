/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ctoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 11:32:04 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 13:21:36 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ctoa(char c)
{
	char	*res;

	if (c == '\0')
		return (ft_strnew(0));
	res = ft_strnew(1);
	if (res == NULL)
		return (NULL);
	res[0] = c;
	return (res);
}
