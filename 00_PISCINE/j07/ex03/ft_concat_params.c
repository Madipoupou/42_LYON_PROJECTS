/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_concat_params.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 01:16:26 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 02:57:52 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		my_strlen(char *str)
{
	int cpt;

	cpt = 0;
	while (str[cpt] != '\0')
		cpt++;
	return (cpt);
}

void	concatenate(char *str, int argc, char **argv, int total)
{
	int argv_num;
	int argv_index;
	int str_index;

	argv_num = 1;
	str_index = 0;
	while (argv_num < argc)
	{
		argv_index = 0;
		while (argv[argv_num][argv_index] != '\0')
		{
			str[str_index] = argv[argv_num][argv_index];
			argv_index++;
			str_index++;
		}
		if (argv_num < argc - 1)
		{
			str[str_index] = '\n';
			str_index++;
		}
		argv_num++;
	}
	str[str_index] = '\0';
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		total;
	char	*str;

	str = NULL;
	i = 1;
	total = 0;
	while (i < argc)
	{
		total += my_strlen(argv[i]);
		i++;
	}
	str = (char*)malloc(total * sizeof(char) + (argc - 1));
	if (!str)
		return (NULL);
	concatenate(str, argc, argv, total);
	return (str);
}
