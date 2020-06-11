/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 10:21:40 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 10:26:49 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include "mem.h"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_lstaddend(t_list **lst, t_list *new);
size_t			ft_lstlen(t_list *lst);
void			ft_lstswap_c(t_list *m1, t_list *m2);
void			ft_lstsort_bc(t_list *lst, int (*cmp)(void *, void *));
void			ft_lststrdel(void *ptr, size_t size);
void			ft_lstremove(t_list **lst,
								t_list **rem,
								void (*del)(void *, size_t));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
