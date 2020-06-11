/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 15:55:04 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 23:05:33 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct	s_list
{
	struct s_list	*next;
	int				x;
}				t_list;
t_list	*ft_create_elem(int x);
void	ft_list_push_back(t_list **begin_list, int x);
void	ft_list_push_front(t_list **begin_list, int x);
int		ft_list_size(t_list *begin_list);
t_list	*ft_list_last(t_list *begin_list);
t_list	*ft_list_push_params(int argc, char **argv);
void	ft_list_clear(t_list **begin_list);
t_list	*ft_list_at(t_list	*begin_list, unsigned int nbr);
void	ft_list_reverse(t_list **begin_list);
void	disp_list(t_list *begin);
void	ft_list_remove_if(t_list **begin_list, int b, int (*cmp)());
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void	ft_list_sort(t_list **begin_list);
void	ft_list_reverse_fun(t_list *begin_list);
void	ft_sorted_list_insert(t_list **begin_list, int x);

#endif
