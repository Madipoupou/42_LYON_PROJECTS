/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_compact.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/13 13:56:17 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/13 15:07:07 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	ft_compact(char **tab, int length)
{
	int		i;
	int		j;
	int		cpt_rem;

	if (length == 0)
		return (0);
	i = 0;
	cpt_rem = 0;
	while (i < length)
	{
		if (tab[i] == 0 && i != (length - 1))
		{
			j = i;
			while (j++ < (length - 1))
			{
				tab[j - 1] = tab[(j - 1) + 1];
				length--;
			}
			continue ;
		}
		else if (tab[i] == 0 && i == (length - 1))
			length--;
		i++;
	}
	return (length);
}
