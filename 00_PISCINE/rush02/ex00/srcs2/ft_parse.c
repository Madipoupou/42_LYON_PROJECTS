/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/22 02:18:00 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 16:35:20 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/my2.h"

t_list	*ft_parse_first_line(t_list *l, char *tab, int tot_char, int num_line)
{
	t_list	*current;

	current = l;
	if (current->c != tab[0])
		return (0);
	current = current->next;
	while (current->c != '\n' && current->next->c != '\n')
	{
		if (current->c != tab[4])
			return (0);
		current = current->next;
	}
	if ((tot_char / num_line) > 1)
	{
		if (current->c != tab[1])
			return (0);
		current = current->next;
	}
	return (current);
}

t_list	*ft_parse_interm_line(t_list *l, char *tab, int tot_char, int num_line)
{
	t_list	*current;
	int		i;

	i = 0;
	current = l;
	while (++i < num_line - 1)
	{
		if (current->c != tab[5])
			return (0);
		current = current->next;
		while (current->c != '\n' && current->next->c != '\n')
		{
			if (current->c != ' ')
				return (0);
			current = current->next;
		}
		if ((tot_char / num_line) > 1)
		{
			if (current->c != tab[5])
				return (0);
			current = current->next;
		}
		current = current->next;
	}
	return (current);
}

t_list	*ft_parse_last_line(t_list *l, char *tab, int tot_char, int num_line)
{
	t_list	*current;

	current = l;
	if (current->c != tab[2])
		return (0);
	current = current->next;
	while (current->c != '\n' && current->next->c != '\n')
	{
		if (current->c != tab[4])
			return (0);
		current = current->next;
	}
	if ((tot_char / num_line) > 1)
	{
		if (current->c != tab[3])
			return (0);
		current = current->next;
	}
	return (current);
}

int		ft_parse_file(t_list *begin, char *tab, int num_line, int tot_char)
{
	t_list	*curr;

	curr = begin;
	if (!(curr = ft_parse_first_line(curr, tab, tot_char, num_line)))
		return (0);
	if (num_line > 1)
	{
		curr = curr->next;
		if (!(curr = ft_parse_interm_line(curr, tab, tot_char, num_line)))
			return (0);
		if (!(curr = ft_parse_last_line(curr, tab, tot_char, num_line)))
			return (0);
	}
	return (1);
}

void	ft_parse(int *possib, int num_line, int tot_char, t_list *begin)
{
	char	**tab;
	int		i;

	tab = ft_create_colle_tab();
	ft_init_colle_tab1(tab);
	ft_init_colle_tab2(tab);
	i = 0;
	while (i < SIZE)
	{
		if (!ft_parse_file(begin, tab[i], num_line, tot_char))
			possib[i] = 0;
		i++;
	}
	ft_clear_table(tab);
}
