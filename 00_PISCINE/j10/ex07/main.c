/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 02:34:11 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 02:47:21 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>

char	**ft_split_whitespaces(char *str);
void	ft_print_word_tables(char **tab);
void	ft_sort_wordtab(char **tab);

int		main(int argc, char **argv)
{
	char **tab;

	if (argc != 2)
		return (0);
	tab = ft_split_whitespaces(argv[1]);
	printf("Voici le tableau de mots:\n");
	ft_print_word_tables(tab);
	printf("\n");
	ft_sort_wordtab(tab);
	printf("Voici le tableau trie:\n");
	ft_print_word_tables(tab);
	return (0);
}
