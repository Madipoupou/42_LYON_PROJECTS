/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_h.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/22 07:59:14 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 22:37:58 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
char	*ft_remove_ws(char *str);
int		eval_expr(char *str);
int		ft_add(int a, int b);
int		ft_sub(int a, int b);
int		ft_mul(int a, int b);
int		ft_div(int a, int b);
int		ft_mod(int a, int b);
int		ft_strlen(char *str);
int		ft_count_par(char *str);
char	*ft_itoa(int nb);
int		ft_atoi(char *str);
char	*ft_extract_par(char *str, int tot_par);
char	*ft_remove(char *str, int i, int j);
char	*ft_insert(char *str, char *substr, int i);
char	*ft_cut(char *str, int i, int j);
int		ft_eval_subexpr(char *str);
int		ft_doop(char c, int a, int b);
int		ft_count_op(char *str);
int		ft_is_operator(char c);

#endif
