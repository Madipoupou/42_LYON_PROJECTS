/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_is_uppercase.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/10 03:27:12 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/10 03:28:08 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	is_uppercase(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

int	ft_str_is_uppercase(char *str)
{
	if (str[0] == '\0')
		return (1);
	return (is_uppercase(str[0]) && ft_str_is_uppercase(&str[1]));
}
