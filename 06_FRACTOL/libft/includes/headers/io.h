/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   io.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 10:21:35 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/20 16:48:19 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H
# include <unistd.h>
# define BUFF_SIZE 32

int				get_next_line(const int fd, char **line);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

#endif
