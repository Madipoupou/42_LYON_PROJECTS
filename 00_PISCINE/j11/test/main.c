/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 18:08:31 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 23:06:41 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

int		ft_cmp(int a, int b)
{
	if (a == b)
		return (0);
	else
		return (1);
}

void	disp_list(t_list *begin)
{
	t_list *current;

	current = begin;
	if (begin != 0)
		printf("MY LIST: ");
	else
		printf("EMPTY LIST!!!\n");
	while (current != 0)
	{
		if (current->next != 0)
			printf("%d - ", current->x);
		else
			printf("%d\n\n", current->x);
		current = current->next;
	}
}

void	disp_list_elt(t_list *elt)
{
	if (elt != 0)
		printf("+++ %d +++\n", elt->x);
}

int		main()
{
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;

	list1 = 0;
	list2 = 0;
	list3 = 0;
	ft_list_push_back(&list1, 40);
	ft_list_push_back(&list1, 30);
	ft_list_push_back(&list1, 90);
	ft_list_push_back(&list1, 0);
	ft_list_push_back(&list1, 10);
	ft_list_push_back(&list1, -20);
	ft_list_push_front(&list1, 255);
	ft_list_push_front(&list1, 102);
	
	disp_list(list1);
	ft_list_sort(&list1);
	disp_list(list1);
	ft_list_reverse_fun(list1);
	disp_list(list1);
	ft_sorted_list_insert(&list1, 999);
	disp_list(list1);
	ft_sorted_list_insert(&list1, -500);
	disp_list(list1);

}
