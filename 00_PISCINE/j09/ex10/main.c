/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/13 07:04:35 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/13 10:15:32 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>

void	ft_scrambler(int ***a, int *b, int *******c, int ****d);

int		main(void)
{
	int a;
	int b;
	int c;
	int d;

	int *ptra;
	int **ptra2;
	int ***ptra3;

	int *ptrb;

	int *ptrc;
	int **ptrc2;
	int ***ptrc3;
	int ****ptrc4;
	int *****ptrc5;
	int ******ptrc6;
	int *******ptrc7;

	int *ptrd;
	int **ptrd2;
	int ***ptrd3;
	int ****ptrd4;

	a = 1;
	ptra = &a;
	ptra2 = &ptra;
	ptra3 = &ptra2;

	b = 10;
	ptrb = &b;

	c = 100;
	ptrc = &c;
	ptrc2 = &ptrc;
	ptrc3 = &ptrc2;
	ptrc4 = &ptrc3;
	ptrc5 = &ptrc4;
	ptrc6 = &ptrc5;
	ptrc7 = &ptrc6;

	d = 1000;
	ptrd = &d;
	ptrd2 = &ptrd;
	ptrd3 = &ptrd2;
	ptrd4 = &ptrd3;

	printf("Valeurs initiales: %d %d %d %d\n\n", a, b, c, d);
	ft_scrambler(ptra3, ptrb, ptrc7, ptrd4);
	printf("Valeurs finales: %d %d %d %d\n\n", a, b, c, d);
}
