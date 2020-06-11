/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 02:34:11 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 03:13:17 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>

char	**ft_split_whitespaces(char *str);
void	ft_print_word_tables(char **tab);
void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char*, char*));

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

int		main(int argc, char **argv)
{
	char	**tab;
	int		(*f)(char*, char*);

	if (argc != 2)
		return (0);
	f = &ft_strcmp;
	tab = ft_split_whitespaces(argv[1]);
	printf("Voici le tableau de mots:\n");
	ft_print_word_tables(tab);
	printf("\n");
	ft_advanced_sort_wordtab(tab, f);
	printf("Voici le tableau trie:\n");
	ft_print_word_tables(tab);
	return (0);
}
