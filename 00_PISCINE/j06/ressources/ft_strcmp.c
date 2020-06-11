/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   str_cmp.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/10 00:52:11 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/10 01:15:11 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	my_strlen4(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (my_strlen4(s1) > 0 && my_strlen4(s2) > 0)
	{
		if (s1[0] == s2[0])
			return (ft_strcmp(&s1[1], &s2[1]));
		return ((int)(s1[0] - s2[0]));
	}
	else if (my_strlen4(s1) == 0)
		return (0 - (int)s2[0]);
	else
		return ((int)s1[0]);
}
