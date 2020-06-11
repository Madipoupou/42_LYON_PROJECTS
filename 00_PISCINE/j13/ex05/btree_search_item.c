/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   btree_search_item.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/20 13:12:54 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/20 13:53:46 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root,
		void *data_ref,
		int (*cmpf)(void *, void *))
{
	if (root == 0 || data_ref == 0)
		return (0);
	if (cmpf(root->item, data_ref) == 0)
		return (root->item);
	if (btree_search_item(root->left, data_ref, cmpf) != 0)
		return (data_ref);
	if (btree_search_item(root->right, data_ref, cmpf) != 0)
		return (data_ref);
	return (0);
}
