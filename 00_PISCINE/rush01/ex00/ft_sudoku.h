/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sudoku.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/13 23:46:28 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/15 21:07:39 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_SUDOKU_H
# define FT_SUDOKU_H
# include <unistd.h>
# include <stdlib.h>
# define TRUE	1
# define FALSE	0
# define SIZE	9

typedef	unsigned int	t_bool;
int						**ft_build_grid(char **argv);
int						ft_strlen(char *str);
void					ft_putchar(char c);
void					ft_putstr(char *str);
void					ft_display_grid(int **grid);
void					ft_free_memory(int **grid, int **grid2);
t_bool					ft_check_linelen(char **argv);
t_bool					ft_check_grid(int **grid);
t_bool					ft_check_block(int **grid, int block_num);
t_bool					ft_solve(int **grid, int **grid2);

#endif
