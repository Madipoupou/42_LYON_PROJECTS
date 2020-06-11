/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_int_arg.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 16:22:47 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 15:24:23 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static long long int	ft_ext(va_list *ap, t_attributes *att)
{
	long long int	x;

	if (att->hh == 1 || att->h == 1)
		x = va_arg(*ap, int);
	else if (att->l == 1)
		x = va_arg(*ap, long int);
	else if (att->ll == 1)
		x = va_arg(*ap, long long int);
	else
		x = va_arg(*ap, int);
	return (x);
}

static void				ft_applyflag(char **res, char *sub, long long int x,
		t_attributes *att)
{
	char	end;

	end = sub[ft_strlen(sub) - 1];
	if (att->prec != -1)
		ft_enhance_left(res, '0', (x < 0 ? att->prec + 1 : att->prec));
	if (x >= 0 && (end == 'd' || end == 'i'))
	{
		if (att->opt2 >= 1)
			ft_enhance_left(res, '+', (int)ft_strlen(*res) + 1);
		else if (att->opt5 >= 1)
			ft_enhance_left(res, ' ', (int)ft_strlen(*res) + 1);
	}
	if (att->opt3 == 1 && end == 'x' && x != 0)
	{
		ft_enhance_left(res, 'x', (int)ft_strlen(*res) + 1);
		ft_enhance_left(res, '0', (int)ft_strlen(*res) + 1);
	}
	if (att->opt3 == 1 && end == 'X' && x != 0)
	{
		ft_enhance_left(res, 'X', (int)ft_strlen(*res) + 1);
		ft_enhance_left(res, '0', (int)ft_strlen(*res) + 1);
	}
	if (att->opt3 == 1 && end == 'o' && att->prec < 1 && !(att->opt3 == 1 &&
				end == 'o' && x == 0 && att->prec == -1))
		ft_enhance_left(res, '0', (int)ft_strlen(*res) + 1);
}

static void				ft_applyflag2(char **res, t_attributes *att)
{
	if (att->width != -1)
	{
		if (att->opt1 == 0)
		{
			if (att->opt4 == 0 || (att->prec != -1))
				ft_enhance_left(res, ' ', att->width);
			else
				ft_enhance_left(res, '0', att->width);
		}
		else
			ft_enhance_right(res, ' ', att->width);
	}
	ft_intadjust(*res, att);
}

char					*pf_int_arg(char *sub, va_list *ap, t_attributes *att)
{
	char				*res;
	long long int		x;

	x = ft_ext(ap, att);
	res = ft_toa1(sub, x, att);
	if (res == NULL)
		res = ft_toa2(sub, x, att);
	if (res == NULL)
		res = ft_toa3(sub, x, att);
	if (res == NULL)
		return (NULL);
	ft_applyflag(&res, sub, x, att);
	ft_applyflag2(&res, att);
	return (res);
}
