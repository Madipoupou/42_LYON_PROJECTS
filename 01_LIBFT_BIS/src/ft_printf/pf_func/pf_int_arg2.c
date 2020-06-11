/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_int_arg.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 16:22:47 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 15:47:12 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_toa1(char *sub, long long int x, t_attributes *att)
{
	char	end;
	char	*res;

	res = NULL;
	end = sub[ft_strlen(sub) - 1];
	if (end == 'd' || end == 'i')
	{
		if (att->h == 1 || att->hh == 1)
			res = (att->h == 1 ? ft_itoa((short)x) : ft_itoa((char)x));
		else
			res = ft_itoa(x);
	}
	else if (end == 'u')
	{
		if (att->h == 1 || att->hh == 1)
			res = (att->h == 1 ? ft_uitoa((unsigned short)x)
					: ft_uitoa((unsigned char)x));
		else if (att->l == 0 && att->ll == 0)
			res = ft_uitoa((unsigned)x);
		else
			res = ft_uitoa(x);
	}
	if (res != NULL && x == 0 && att->prec == 0)
		ft_delzero(&res);
	return (res);
}

char	*ft_toa2(char *sub, long long int x, t_attributes *att)
{
	char	end;
	char	*res;

	res = NULL;
	end = sub[ft_strlen(sub) - 1];
	if (end == 'o')
	{
		if (att->h == 1 || att->hh == 1)
			res = (att->hh == 1 ? ft_uitoabase((unsigned char)x, 8)
					: ft_uitoabase((unsigned short)x, 8));
		else
			res = (att->l == 0 && att->ll == 0 ?
					ft_uitoabase((unsigned int)x, 8) : ft_uitoabase(x, 8));
	}
	if (x == 0 && att->prec == 0)
		ft_delzero(&res);
	return (res);
}

char	*ft_toa3(char *sub, long long int x, t_attributes *att)
{
	char	end;
	char	*res;

	res = NULL;
	end = sub[ft_strlen(sub) - 1];
	if (end == 'x' || end == 'X')
	{
		if (att->hh == 1 || att->h == 1)
			res = (att->hh == 1 ? ft_uitoabase((unsigned char)x, 16)
					: ft_uitoabase((unsigned short)x, 16));
		else
			res = (att->l == 0 && att->ll == 0 ?
					ft_uitoabase((unsigned)x, 16) : ft_uitoabase(x, 16));
		if (end == 'X')
			ft_strtoupper(res);
	}
	if (x == 0 && att->prec == 0)
		ft_delzero(&res);
	return (res);
}
