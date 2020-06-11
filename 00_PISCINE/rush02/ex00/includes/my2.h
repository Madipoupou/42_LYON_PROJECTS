/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   my2.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/21 22:11:17 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 16:40:19 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MY2_H
# define MY2_H
# define SIZE	5
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_list
{
	char			c;
	struct s_list	*next;
}				t_list;
t_list			*ft_create_elem(char c);
void			ft_disp_list(t_list *begin);
void			ft_clean_list(t_list *begin);
void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_fill_list(t_list **begin, int *tot_char);
void			ft_disp(int colle, int line_num, int line_len);
void			ft_error(void);
void			ft_init_tab(int *possib);
void			ft_putnbr(int n);
void			ft_result(int *possib, int line_num, int line_len);
void			ft_parse(int *possib, int num_line, int tot_char, t_list *b);
char			**ft_create_colle_tab(void);
void			ft_init_colle_tab1(char **tab);
void			ft_init_colle_tab2(char **tab);
void			ft_clear_table(char **tab);

#endif
