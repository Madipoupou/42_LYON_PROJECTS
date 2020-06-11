/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 11:34:36 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 09:33:03 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dest;
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char *)malloc(n * sizeof(char));
	if (temp != NULL && n > 0)
	{
		temp_src = (unsigned char *)src;
		temp_dest = (unsigned char *)dest;
		i = -1;
		while (++i < n)
			temp[i] = temp_src[i];
		i = -1;
		while (++i < n)
			temp_dest[i] = temp[i];
	}
	if (temp != NULL)
		free(temp);
	return (dest);
}
