/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_rot42.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 21:53:26 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 22:32:11 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	decal_min(char c)
{
	char	res;
	int		i;

	res = c;
	i = 0;
	while (i < (42 % 26))
	{
		res++;
		if (res > 122)
			res = 97;
		i++;
	}
	return (res);
}

char	decal_maj(char c)
{
	char	res;
	int		i;

	res = c;
	i = 0;
	while (i < (42 % 26))
	{
		res++;
		if (res > 90)
			res = 65;
		i++;
	}
	return (res);
}

char	*ft_rot42(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = decal_min(str[i]);
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = decal_maj(str[i]);
		i++;
	}
	return (str);
}
