/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/19 01:42:27 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/19 16:40:04 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# define BUF_SIZE 10

void	ft_putchar(char c, int fd);
void	ft_putstr(char *str, int fd);
void	ft_readfile(int fd);
void	ft_error_manager(int err, char *str);
void	ft_infinity_loop(void);
int		ft_strlen(char *str);

#endif
