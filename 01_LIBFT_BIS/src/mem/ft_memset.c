/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 09:45:31 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 09:23:32 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;

	if (n > 0)
	{
		temp = (unsigned char *)s;
		while (n > 0)
		{
			*temp = (unsigned char)c;
			temp++;
			n--;
		}
	}
	return (s);
}
