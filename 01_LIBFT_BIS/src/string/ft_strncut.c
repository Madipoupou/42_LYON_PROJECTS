/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncut.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 14:02:19 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 14:59:42 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_strncut(char **str, size_t i, size_t j)
{
	char	*temp;
	char	*sub1;
	char	*sub2;

	temp = *str;
	if ((sub1 = ft_strsub(*str, 0, i + 1)) == NULL)
		return ;
	if ((sub2 = ft_strsub(*str, j + 1, (ft_strlen(*str) - (j + 1)))) == NULL)
	{
		free(sub1);
		return ;
	}
	if ((temp = ft_strjoin(sub1, sub2)) == NULL)
	{
		free(sub1);
		free(sub2);
		return ;
	}
	free(*str);
	free(sub1);
	free(sub2);
	*str = temp;
}
