/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 10:56:56 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 08:03:33 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
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
			if (*temp_dest == (unsigned char)c)
				return ((void *)temp_dest + 1);
			temp_dest++;
			temp_src++;
			n--;
		}
	}
	return (NULL);
}
