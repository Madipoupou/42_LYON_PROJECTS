/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_pc_arg.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 10:57:46 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 15:48:23 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../../includes/libft.h"

static void	ft_addw(char **res, int width, int zero, int minus)
{
	char	*final;
	int		i;

	final = ft_strnew(width);
	if (final == NULL)
	{
		free(*res);
		*res = NULL;
		return ;
	}
	if (minus == 0)
	{
		final[width - 1] = '%';
		i = 0;
	}
	else
	{
		final[0] = '%';
		i = 1;
	}
	while (i < width - 1)
		final[i++] = (zero == 1 ? '0' : ' ');
	final[width - 1] = (minus == 0 ? '%' : final[width - 2]);
	free(*res);
	*res = final;
}

char		*pf_pc_arg(char *sub, va_list *ap, t_attributes *att)
{
	char	*res;

	if (sub != NULL && ap != NULL)
	{
		;
	}
	res = ft_strdup("%");
	if (res == NULL)
		return (NULL);
	if (att->width != -1)
		ft_addw(&res, att->width, att->opt4, att->opt1);
	return (res);
}
