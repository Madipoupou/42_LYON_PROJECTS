/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_is_lowercase.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/10 03:25:21 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/10 03:25:32 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	is_lowercase(char c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

int	ft_str_is_lowercase(char *str)
{
	if (str[0] == '\0')
		return (1);
	return (is_lowercase(str[0]) && ft_str_is_lowercase(&str[1]));
}
