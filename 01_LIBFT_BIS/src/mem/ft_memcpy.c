/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 10:11:17 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 09:29:09 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dest;

	if (n > 0)
	{
		temp_src = (unsigned char *)src;
		temp_dest = (unsigned char *)dest;
		while (n > 0)
		{
			*temp_dest = *temp_src;
			temp_dest++;
			temp_src++;
			n--;
		}
	}
	return (dest);
}
