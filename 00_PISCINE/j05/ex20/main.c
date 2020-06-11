/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/10 14:23:29 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/10 23:29:44 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include	<stdio.h>

void	ft_putnbr_base(int nbr, char *str);

int		main(void)
{
	int		nbr;
	char	str[79] = {'\0'};

	do
	{
		printf("Saisir un nombre: ");
		scanf("%d", &nbr);
		if (nbr == -1)
			break ;
		while (getchar() != '\n');
		printf("Saisir une base: ");
		gets(str);

		printf("\n");
		ft_putnbr_base(nbr, str);
		printf("\n");
	}while (1);
	return (0);
}
