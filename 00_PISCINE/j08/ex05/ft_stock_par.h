/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stock_par.h                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 14:30:36 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/13 01:27:54 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_STOCK_PAR_H
# define FT_STOCK_PAR_H
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_stock_par
{
	int		size_param;
	char	*str;
	char	*copy;
	char	**tab;
}				t_stock_par;
char			**ft_split_whitespaces(char *str);
t_stock_par		*ft_param_to_tab(int ac, char **av);
void			ft_putchar(char c);

#endif
