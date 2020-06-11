/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   btree_level_count.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/20 13:57:37 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/20 14:19:21 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_btree.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	btree_level_count(t_btree *root)
{
	if (root == 0)
		return (0);
	if (root->left == 0 && root->right == 0)
		return (1);
	return (1 + ft_max(
				btree_level_count(root->left),
				btree_level_count(root->right)));
}
