/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_c_arg.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 11:29:21 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 15:44:49 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../../includes/libft.h"

static void	ft_applyflag1(char **res, t_attributes *att, char c)
{
	if (att->width != -1)
	{
		if (att->opt1 == 1)
			ft_enhance_right(res, ' ', (c == '\0' ? att->width +
						(int)ft_strlen(N) - 1 : att->width));
		else
		{
			if (att->opt4 == 0)
				ft_enhance_left(res, ' ', (c == '\0' ? att->width +
						(int)ft_strlen(N) - 1 : att->width));
			else
				ft_enhance_left(res, '0', (c == '\0' ? att->width +
						(int)ft_strlen(N) - 1 : att->width));
		}
	}
}

char		*pf_c_arg(char *sub, va_list *ap, t_attributes *att)
{
	char	*res;
	char	c;

	if (sub)
	{
		;
	}
	c = (char)va_arg(*ap, int);
	if (c == 0)
		res = ft_strdup(N);
	else
		res = ft_ctoa(c);
	if (res == NULL)
		return (NULL);
	ft_applyflag1(&res, att, c);
	return (res);
}
