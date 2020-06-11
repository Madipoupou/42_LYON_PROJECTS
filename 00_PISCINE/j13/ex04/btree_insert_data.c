/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   btree_insert_data.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/20 10:16:24 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/20 13:09:30 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root,
		void *item,
		int (*cmpf)(void *, void *))
{
	t_btree *tbt_curr;

	if (root == 0)
		return ;
	if (*root == 0)
		*root = btree_create_node(item);
	else
	{
		tbt_curr = *root;
		if ((*cmpf)(item, tbt_curr->item) < 0)
		{
			if (tbt_curr->left != 0)
				btree_insert_data(&(tbt_curr->left), item, cmpf);
			else
				tbt_curr->left = btree_create_node(item);
		}
		else
		{
			if (tbt_curr->right != 0)
				btree_insert_data(&(tbt_curr->right), item, cmpf);
			else
				tbt_curr->right = btree_create_node(item);
		}
	}
}
