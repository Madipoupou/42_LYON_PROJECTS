/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 19:52:16 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/10 00:45:59 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		my_strlen3(char *str)
{
	int cpt;

	cpt = 0;
	while (str[cpt] != '\0')
		cpt++;
	return (cpt);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	mem_i;

	if (my_strlen3(to_find) == 0)
		return (str);
	i = -1;
	while (++i < my_strlen3(str))
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			mem_i = i;
			while (++j < my_strlen3(to_find) && ++i < my_strlen3(str))
			{
				if (str[i] != to_find[j])
					break ;
			}
			if (j == my_strlen3(to_find))
				return (&str[mem_i]);
			i = mem_i;
		}
	}
	return (0);
}
