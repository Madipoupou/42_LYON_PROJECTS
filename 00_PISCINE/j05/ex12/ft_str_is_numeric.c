/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_is_numeric.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/10 03:26:10 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/10 03:26:13 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	is_numeric(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_str_is_numeric(char *str)
{
	if (str[0] == '\0')
		return (1);
	return (is_numeric(str[0]) && ft_str_is_numeric(&str[1]));
}
