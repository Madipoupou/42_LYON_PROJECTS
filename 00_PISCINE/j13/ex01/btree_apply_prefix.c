/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   btree_apply_prefix.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/20 09:42:17 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/20 10:05:45 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, void (*applyf)(void*))
{
	if (root != 0)
	{
		(*applyf)(root->item);
		if (root->left != 0)
			btree_apply_prefix(root->left, applyf);
		if (root->right != 0)
			btree_apply_prefix(root->right, applyf);
	}
}
