/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 21:57:42 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 22:32:30 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_rot42(char *str);

int		main(void)
{
	char	str[] = "Je n'ai pas fini tout le boulot.";

	printf("Ma chaine: %s\n", ft_rot42(str));
	return (0);
}
