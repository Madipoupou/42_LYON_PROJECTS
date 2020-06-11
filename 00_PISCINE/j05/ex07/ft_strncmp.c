/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/10 01:22:37 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/10 01:45:15 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	my_strlen5(char *c)
{
	int i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (n <= 0)
		return (0);
	if (my_strlen5(s1) > 0 && my_strlen5(s2) > 0)
	{
		if (s1[0] == s2[0])
			return (ft_strncmp(&s1[1], &s2[1], (n - 1)));
		return ((int)(s1[0] - s2[0]));
	}
	else if (my_strlen5(s1) == 0)
		return (0 - (int)s2[0]);
	else
		return ((int)s1[0]);
}
