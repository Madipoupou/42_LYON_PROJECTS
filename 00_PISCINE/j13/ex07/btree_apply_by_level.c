/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   btree_apply_by_level.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/20 14:29:22 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/20 15:45:24 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_btree.h"

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int		btree_level_count2(t_btree *root)
{
	if (root == 0)
		return (0);
	if (root->left == 0 && root->right == 0)
		return (1);
	return (1 + ft_max(
				btree_level_count(root->left),
				btree_level_count(root->right)));
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	h_tot;
	int	i;

	h_tot = btree_level_count2(root);
	i = 0;

}
