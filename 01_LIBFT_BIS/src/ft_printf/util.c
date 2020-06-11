/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 09:34:09 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 16:07:01 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr_pf(char *str, int fd)
{
	char	*add;
	int		cpt;

	cpt = 0;
	add = ft_strstr(str, N);
	if (add == NULL)
		write(fd, str, ft_strlen(str));
	else
	{
		cpt++;
		while (str < add)
		{
			ft_putchar_fd(*str, fd);
			str++;
		}
		ft_putchar_fd('\0', fd);
		cpt += ft_putstr_pf(str + ft_strlen(N), fd);
	}
	return (cpt);
}

void	ft_delzero(char **res)
{
	char	*temp;

	temp = ft_strnew(0);
	free(*res);
	*res = temp;
}

void	ft_enhance_left(char **res, char c, int len)
{
	char	*temp;
	int		old_len;
	int		i;
	int		j;

	old_len = (int)ft_strlen(*res);
	if (old_len >= len)
		return ;
	temp = ft_strnew(len);
	if (temp == NULL)
		return ;
	i = 0;
	while (i < (len - old_len))
		temp[i++] = c;
	j = 0;
	while (i < len)
		temp[i++] = (*res)[j++];
	free(*res);
	*res = temp;
}

void	ft_enhance_right(char **res, char c, int len)
{
	char	*temp;
	int		old_len;
	int		i;

	old_len = (int)ft_strlen(*res);
	if (old_len >= len)
		return ;
	temp = ft_strnew(len);
	if (temp == NULL)
		return ;
	i = -1;
	while (++i < old_len)
		temp[i] = (*res)[i];
	while (i < len)
		temp[i++] = c;
	free(*res);
	*res = temp;
}

void	ft_intadjust(char *res, t_attributes *att)
{
	int		i;
	int		j;
	int		len;
	char	c;

	len = (int)ft_strlen(res);
	i = 0;
	while (res[i] == ' ')
		i++;
	if (res[i] != '0' || (res[i] == '0' && att->opt1 == 1))
		return ;
	j = i;
	while (j < len && res[j] != '+' && res[j] != '-' &&
			res[j] != 'x' && res[j] != 'X' && res[j] != ' ')
		j++;
	if (j == len)
		return ;
	if (res[j] == 'x' || res[j] == 'X')
		i++;
	c = res[i];
	res[i] = res[j];
	res[j] = c;
	return ;
}
