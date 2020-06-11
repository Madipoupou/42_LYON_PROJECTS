/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_p_arg.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 11:41:53 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 15:47:50 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	ft_applyflag(char **res, long long unsigned addr,
		t_attributes *att)
{
	char	*temp;

	if (addr == 0 && att->prec == 0)
	{
		temp = ft_strdup("");
		if (temp == NULL)
			return ;
		free(*res);
		*res = temp;
	}
	else if (addr == 0 && att->prec > 0)
		ft_enhance_right(res, '0', att->prec);
	else if (att->prec > 0)
		ft_enhance_left(res, '0', att->prec);
	ft_enhance_left(res, 'x', ft_strlen(*res) + 1);
	ft_enhance_left(res, '0', ft_strlen(*res) + 1);
	if (att->width != -1)
	{
		if (att->opt1 == 1)
			ft_enhance_right(res, ' ', att->width);
		else
			ft_enhance_left(res, ' ', att->width);
	}
}

char		*pf_p_arg(char *sub, va_list *ap, t_attributes *att)
{
	char					*res;
	void					*arg;
	long long unsigned int	addr;

	if (sub)
	{
		;
	}
	arg = va_arg(*ap, void *);
	addr = (long long unsigned int)arg;
	res = ft_uitoabase(addr, 16);
	if (res == NULL)
		return (NULL);
	ft_applyflag(&res, addr, att);
	return (res);
}
