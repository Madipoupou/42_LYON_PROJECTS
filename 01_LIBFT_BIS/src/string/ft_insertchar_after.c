/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_insertchar_after.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 17:02:19 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 17:11:29 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_insertchar_after(char **str, char c, int index)
{
	char	*temp;
	int		i;

	if (str == NULL || *str == NULL)
		return ;
	temp = ft_strnew(ft_strlen(*str) + 1);
	if (temp == NULL)
		return ;
	i = 0;
	while (i <= index)
	{
		temp[i] = (*str)[i];
		i++;
	}
	temp[i++] = c;
	while ((*str)[i - 1] != '\0')
	{
		temp[i] = (*str)[i - 1];
		i++;
	}
	free(*str);
	*str = temp;
}
