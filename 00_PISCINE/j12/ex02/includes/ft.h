/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/19 16:50:10 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/19 17:35:15 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <stderr.h>
# include <fcntl.h>
# include <stdlib.h>

int		ft_atoi(char *str);
int		ft_strlen(char *str);
void	ft_error(char *str_file);

#endif
