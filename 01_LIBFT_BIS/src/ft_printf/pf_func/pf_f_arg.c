/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_f_arg.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 12:07:54 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 16:16:56 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static long double	ft_extract(va_list *ap, t_attributes *att)
{
	long double	f;

	if (att->longd == 1)
		f = va_arg(*ap, long double);
	else if (att->l == 1)
		f = (long double)va_arg(*ap, double);
	else
		f = (long double)va_arg(*ap, double);
	return (f);
}

static void			ft_applyflag(char **res, t_attributes *att,
		long double f)
{
	if (att->opt2 == 1 && f > 0)
		ft_enhance_left(res, '+', ((int)ft_strlen(*res) + 1));
	else if (att->opt5 == 1 && f > 0)
		ft_enhance_left(res, ' ', ((int)ft_strlen(*res) + 1));
}

static void			ft_applyflag2(char **res, t_attributes *att)
{
	if (att->width != -1)
	{
		if (att->opt1 == 0)
		{
			if (att->opt4 == 0)
				ft_enhance_left(res, ' ', att->width);
			else
				ft_enhance_left(res, '0', att->width);
		}
		else
			ft_enhance_right(res, ' ', att->width);
	}
	ft_intadjust(*res, att);
}

char				*pf_f_arg(char *sub, va_list *ap, t_attributes *att)
{
	char		*res;
	long double	f;

	if (sub != NULL)
	{
		;
	}
	f = ft_extract(ap, att);
	res = ft_ldtoa(f, (att->prec == -1 ? 6 : att->prec));
	if (res == NULL)
		return (res);
	ft_applyflag(&res, att, f);
	ft_applyflag2(&res, att);
	return (res);
}
