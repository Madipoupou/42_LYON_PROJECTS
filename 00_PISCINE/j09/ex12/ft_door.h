/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_door.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/13 12:51:56 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/13 13:53:14 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_DOOR_H
# define FT_DOOR_H
# define TRUE 1
# define FALSE 0
# define CLOSE 0
# define OPEN 1
# include <unistd.h>

typedef unsigned char	t_bool;
typedef	struct			s_door
{
	t_bool state;
}						t_door;
void					ft_putstr(char *str);
t_bool					open_door(t_door *door);
t_bool					close_door(t_door *door);
t_bool					is_door_open(t_door *door);
t_bool					is_door_close(t_door *door);

#endif
