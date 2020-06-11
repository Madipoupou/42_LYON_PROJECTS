/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_advanced_sort_wordtab.c                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 02:53:14 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 03:15:29 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char*, char*))
{
	int		i;
	int		j;

	i = 0;
	while (tab[i] != 0)
	{
		if (tab[i] == 0)
			break ;
		j = i + 1;
		while (tab[j] != 0)
		{
			if ((*cmp)(tab[i], tab[j]) > 0)
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}
