/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fprintf.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 15:58:23 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 14:02:44 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int					ft_fprintf(int fd, const char *format, ...)
{
	char	*str;
	va_list	ap;
	size_t	len_ret;
	size_t	i;

	if (format == NULL || fd == -1)
		return (0);
	if (ft_color_manager(format) == 1)
		return (1);
	if ((str = ft_strdup(format)) == NULL)
		return (-1);
	va_start(ap, format);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			ft_dispatch(&str, &i, &ap);
		i++;
	}
	i = ft_putstr_pf(str, fd);
	va_end(ap);
	len_ret = (int)ft_strlen(str) - (i * ft_strlen(N)) + i;
	free(str);
	return (len_ret);
}
