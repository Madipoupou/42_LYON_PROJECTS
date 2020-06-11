/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split_whitespaces.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 03:00:03 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 09:51:25 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		eval_word_size(char *str, int index)
{
	int size;
	int i;

	size = 0;
	i = index;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

int		count_words(char *str, int pos)
{
	int	cpt;
	int i;
	int	in_word;

	i = 0;
	cpt = 0;
	in_word = 0;
	while (str[i] != '\0')
	{
		if (!in_word && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			in_word = 1;
			cpt++;
		}
		else if (in_word && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			in_word = 0;
		if (pos != 0 && cpt == pos)
			return (i);
		i++;
	}
	return (cpt);
}

char	*find_word(char *str, int pos)
{
	char	*sub_str;
	int		word_size;
	int		i;
	int		j;

	i = count_words(str, pos);
	word_size = eval_word_size(str, i);
	sub_str = (char*)malloc(word_size * sizeof(char) + 1);
	if (!sub_str)
		return (NULL);
	j = 0;
	while (j < word_size)
	{
		sub_str[j] = str[i];
		j++;
		i++;
	}
	sub_str[j] = '\0';
	return (sub_str);
}

char	**ft_split_whitespaces(char *str)
{
	char	**word_tab;
	int		i;
	char	*temp_str;
	int		tot_word;
	int		len;

	tot_word = count_words(str, 0);
	word_tab = (char**)malloc(tot_word * sizeof(char*) + 1);
	if (!word_tab)
		return (NULL);
	i = 0;
	while (i < tot_word)
	{
		temp_str = find_word(str, (i + 1));
		len = 0;
		while (temp_str[len] != '\0')
			len++;
		word_tab[i] = (char*)malloc(len * sizeof(char) + 1);
		if (!word_tab[i])
			return (NULL);
		word_tab[i] = temp_str;
		i++;
	}
	word_tab[i] = NULL;
	return (word_tab);
}
