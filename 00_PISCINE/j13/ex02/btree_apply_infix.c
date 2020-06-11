/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   btree_apply_infix.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/20 10:07:11 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/20 10:09:53 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_infix(t_btree *root, void (*applyf)(void*))
{
	if (root != 0)
	{
		if (root->left != 0)
			btree_apply_infix(root->left, applyf);
		(*applyf)(root->item);
		if (root->right != 0)
			btree_apply_infix(root->right, applyf);
	}
}
