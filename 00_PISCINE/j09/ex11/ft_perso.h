/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_perso.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/13 11:42:50 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/13 11:55:33 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PERSO_H
# define FT_PERSO_H
# define SAVE_THE_WORLD	1
# include <string.h>

typedef struct	s_perso
{
	char			*name;
	double			life;
	unsigned int	age;
	unsigned int	profession;
}				t_perso;

#endif
