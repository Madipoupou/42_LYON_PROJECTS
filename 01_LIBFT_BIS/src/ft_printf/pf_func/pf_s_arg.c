/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_s_arg.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 11:26:43 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 15:49:03 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	ft_applyflag1(char **res, t_attributes *att)
{
	char	*temp;

	if (att->prec != -1)
		if (att->prec < (int)ft_strlen(*res))
		{
			temp = ft_strsub(*res, 0, att->prec);
			if (temp == NULL)
				return ;
			free(*res);
			*res = temp;
		}
	if (att->width != -1)
	{
		if (att->opt1 > 0)
			ft_enhance_right(res, ' ', att->width);
		else
		{
			if (att->opt4 > 0)
				ft_enhance_left(res, '0', att->width);
			else
				ft_enhance_left(res, ' ', att->width);
		}
	}
}

char		*pf_s_arg(char *sub, va_list *ap, t_attributes *att)
{
	char	*res;

	if (sub != NULL)
	{
		;
	}
	res = va_arg(*ap, char *);
	if (res == NULL && att->prec == -1)
		return (ft_strdup("(null)"));
	else if (res == NULL)
		res = ft_strdup("0");
	else
		res = ft_strdup(res);
	if (res == NULL)
		return (NULL);
	ft_applyflag1(&res, att);
	return (res);
}
