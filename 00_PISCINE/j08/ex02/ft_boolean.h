/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_boolean.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 12:06:28 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 13:32:34 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# include <unistd.h>
# define TRUE		1
# define FALSE		0
# define ODD_MSG	"I have an odd number of arguments.\n"
# define EVEN_MSG	"I have an even number of arguments.\n"
# define SUCCESS	1
# define EVEN(x)	(x % 2 == 0)

typedef unsigned char	t_bool;
void					ft_putstr(char *str);
t_bool					ft_is_even(int nbr);
#endif
