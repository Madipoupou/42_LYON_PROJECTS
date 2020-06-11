/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/13 11:41:51 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/13 11:48:12 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_perso.h"

int main()
{
	t_perso jack;
	jack.name = strdup("jack");
	jack.life = 100.0;
	jack.age = 42;
	jack.profession = SAVE_THE_WORLD;
	return (0);
}
