/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_is_printable.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/10 03:49:33 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/10 03:49:38 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int	ft_str_is_printable(char *str)
{
	if (str[0] == '\0')
		return (1);
	return (is_printable(str[0]) && ft_str_is_printable(&str[1]));
}
