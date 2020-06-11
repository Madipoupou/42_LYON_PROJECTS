/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   btree_create_node.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/20 08:55:09 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/20 09:01:36 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*tbt;

	tbt = (t_btree*)malloc(sizeof(t_btree));
	if (!tbt)
		return (0);
	tbt->item = item;
	tbt->left = 0;
	tbt->right = 0;
	return (tbt);
}
