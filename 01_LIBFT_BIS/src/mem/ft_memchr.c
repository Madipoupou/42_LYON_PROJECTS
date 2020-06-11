/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 11:53:37 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 09:35:10 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;

	if (n != 0)
	{
		temp = (unsigned char *)s;
		while (n > 0)
		{
			if (*temp == (unsigned char)c)
				return (temp);
			temp++;
			n--;
		}
	}
	return (NULL);
}
