/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   btree_apply_suffix.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/20 10:11:18 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/20 10:12:54 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_suffix(t_btree *root, void (*applyf)(void*))
{
	if (root != 0)
	{
		if (root->left != 0)
			btree_apply_suffix(root->left, applyf);
		if (root->right != 0)
			btree_apply_suffix(root->right, applyf);
		(*applyf)(root->item);
	}
}
