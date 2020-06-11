/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_scrambler.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/13 06:45:24 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/13 10:16:09 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_scrambler(int ***a, int *b, int *******c, int ****d)
{
	int tempa;
	int tempb;
	int tempc;
	int tempd;

	tempa = ***a;
	tempb = *b;
	tempc = *******c;
	tempd = ****d;
	*******c = tempa;
	****d = tempc;
	*b = tempd;
	***a = tempb;
}
