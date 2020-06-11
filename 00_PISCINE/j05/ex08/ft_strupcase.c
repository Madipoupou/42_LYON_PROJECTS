/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strupcase.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/10 01:53:00 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/10 02:03:05 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		my_strlen6(char *str)
{
	int cpt;

	cpt = 0;
	while (str[cpt] != '\0')
		cpt++;
	return (cpt);
}

char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (i < my_strlen6(str))
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
		i++;
	}
	return (str);
}
