/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_b_arg.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 16:35:58 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 17:11:39 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void				ft_cleanb(char **str, int index)
{
	index -= 4;
	if (index < 0)
		return ;
	ft_insertchar_after(str, ' ', index);
	ft_cleanb(str, index);
}

static long long int	ft_ext(va_list *ap, t_attributes *att)
{
	long long int	x;

	if (att->l == 1)
		x = (unsigned long)va_arg(*ap, long int);
	else if (att->ll == 1)
		x = (unsigned long long)va_arg(*ap, long long int);
	else
		x = (unsigned)va_arg(*ap, int);
	return (x);
}

static void				ft_applyflag(char **res, char *sub, long long int x,
		t_attributes *att)
{
	if (sub != NULL)
	{
		;
	}
	if (att->prec != -1)
		ft_enhance_left(res, '0', (x < 0 ? att->prec + 1 : att->prec));
	if (att->opt5 == 1)
		ft_cleanb(res, (int)ft_strlen(*res) - 1);
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
}

char					*pf_b_arg(char *sub, va_list *ap, t_attributes *att)
{
	char				*res;
	long long int		x;

	x = ft_ext(ap, att);
	res = ft_uitoabase(x, 2);
	if (res == NULL)
		return (NULL);
	ft_applyflag(&res, sub, x, att);
	return (res);
}
