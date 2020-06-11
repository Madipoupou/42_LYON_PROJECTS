/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_eight_queens_puzzle.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/07 19:53:55 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/07 23:52:00 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define	SIZE 8

void    queen_placer(int tab[SIZE][SIZE], int posi, int posj, int task);
void    queen_placer_diag1(int tab[SIZE][SIZE], int posi, int posj, int task);
void    queen_placer_diag2(int tab[SIZE][SIZE], int posi, int posj, int task);
void    initialisation_tab(int tab[SIZE][SIZE]);
void    disp_tab(int tab[8][8]);
void	reset(int tab[SIZE][SIZE]);

void	pause(void)
{
	printf("\n\nPRESSER ENTREE...\n\n");
	while (getchar() != '\n');
}

void	queen_placer(int tab[SIZE][SIZE], int posi, int posj, int task)
{
	int i;
	int j;
	
	tab[posi][posj] = 3 * task;

	i = 0;
	j = 0;
	while (i < SIZE && j < SIZE)
	{
		if (i != posj && tab[posi][i] != 3)
			tab[posi][i] = task;
		if (i != posi && tab[i][posj] != 3)
			tab[i][posj] = task;
		i++;
		j++;
	}

	queen_placer_diag1(tab, posi, posj, task);
	queen_placer_diag2(tab, posi, posj, task);
	if (!task)
		reset(tab);
}

void	reset(int tab[SIZE][SIZE])
{
	int i;
	int j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if (tab[i][j] == 3)
				queen_placer(tab, i, j, 1);
			j++;
		}
		i++;
	}
}

void	queen_placer_diag1(int tab[SIZE][SIZE], int posi, int posj, int task)
{
	int cpt;
	int test1;
	int test2;

	test1 = 1;
	cpt = 1;
	while  (test1 || test2)
	{
		test1 = (posj - cpt) >= 0 && (posi - cpt) >= 0;
		if (test1)
		{
			if (tab[posi - cpt][posj - cpt] != 3)
				tab[posi + cpt][posj + cpt] = task;
		}
		test2 = ((posj + cpt) <= SIZE && (posi + cpt) <= SIZE);
		if (test2)
		{
			if (tab[posi + cpt][posj + cpt] != 3)
				tab[posi + cpt][posj + cpt] = task;
		}
		cpt++;
	}
}

void	queen_placer_diag2(int tab[SIZE][SIZE], int posi, int posj, int task)
{
	int i;
	int j;

	i = posi - 1;
	j = posj + 1;
	while (i >= 0 && j <= SIZE)
	{
		if (tab[i][j] != 3)
			tab[i][j] = task;
		i--;
		j++;
	}
	i = posi + 1;
	j = posj - 1;
	while (i <= SIZE && j >= 0)
	{
		if (tab[i][j] != 3)
			tab[i][j] = task;
		i++;
		j--;
	}
}

void	initialisation_col(int tab[SIZE][SIZE], int j)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		tab[i][j] = 0;
		i++;
	}
}

int		is_possible(int tab[SIZE][SIZE], int j)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		if (tab[i][j] == 0)
			return (1);
		i++;
	}
	return (0);
}

int		is_full(int tab[SIZE][SIZE])
{
	int i;
	int j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if (tab[i][j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	blabla(int tab[SIZE][SIZE], int j, int *res)
{
	printf("\nres = %d\n", *res);
	int i;

	disp_tab(tab);
	pause();

	if (j >= SIZE)
	{
		*res = *res + 1;
		return;
	}
	if (!is_possible(tab, j) || is_full(tab))
	{
		reset(tab);
		return;
	}
	i = -1;
	while (++i < SIZE)
	{
		if (tab[i][j] == 0)
		{
			queen_placer(tab, i, j, 1);
			blabla(tab, (j + 1), res);
			queen_placer(tab, i, j, 0);
			initialisation_col(tab, j);
		}
	}
	return;
}

/* USELESS */
void	disp_tab(int tab[8][8])
{
	int i;
	int j;

	i = 0;
	printf("\n");
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			printf("%d  ", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int		ft_eight_queens_puzzle(void)
{
	int	grid[SIZE][SIZE];
	int res;
	int i;
	int j;

	res = 0;
	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	disp_tab(grid);
	blabla(grid, 0, &res);
	printf("\n\n%d possibilites.\n", res);

	return (0);
}
