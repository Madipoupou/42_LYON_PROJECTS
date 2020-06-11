/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   antidote.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 23:03:45 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 23:18:03 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	ft_antidote(int i, int j, int k)
{
	if (i < j)
	{
		if (j < k)
			return (j);
		else if (i < k)
			return (k);
		else
			return (i);
	}
	else
	{
		if (i < k)
			return (i);
		else if (k < j)
			return (j);
		else
			return (k);
	}
}
