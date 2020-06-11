/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 12:05:01 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 09:55:08 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *temp_s1;
	unsigned char *temp_s2;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*temp_s1 != *temp_s2)
			return (*temp_s1 - *temp_s2);
		temp_s1++;
		temp_s2++;
		n--;
	}
	return (0);
}
