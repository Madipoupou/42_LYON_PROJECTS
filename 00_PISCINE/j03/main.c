/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/06 09:12:51 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/07 12:19:55 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c);
void	ft_ft(int *nbr);
void	ft_ultimate_ft(int *********nbr);
void	ft_swap(int *a, int *b);
void	ft_div_mod(int a, int b, int *div, int *mod);
void	ft_ultimate_div_mod(int *a, int *b);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strrev(char *str);
void	ft_sort_integer_table(int *tab, int size);
int		ft_atoi(char *str);

int main(void)
{
	/*	EXERCICE 0	*/
	/*
	int n;
	n = 5;
	printf("n = %d\n", n);
	ft_ft(&n);
	printf("n = %d\n\n", n);
	*/

	/*	EXERCICE 1		*/
	/*
	int	nb;
	int	*p1;
	int	**p2;
	int	***p3;
	int	****p4;
	int *****p5;
	int ******p6;
	int *******p7;
	int ********p8;
	int *********p9;
	nb = 21;
	p1 = &nb;
	p2 = &p1;
	p3 = &p2;
	p4 = &p3;
	p5 = &p4;
	p6 = &p5;
	p7 = &p6;
	p8 = &p7;
	p9 = &p8;
	printf("nb = %d\n", nb);
	ft_ultimate_ft(p9);
	printf("nb = %d\n\n", nb);
	*/

	/*	EXERCICE 2		*/
	/*
	int a;
	int b;

	a = 0;
	b = 12;
	printf("a = %d, b = %d\n", a, b);
	ft_swap(&a, &b);
	printf("a = %d, b = %d\n\n", a, b);
	*/

	/*	EXERCICE 3		*/
	/*
	int a;
	int b;
	int div;
	int mod;
	a = 10;
	b = 3;
	ft_div_mod(a, b, &div, &mod);
	printf("%d / %d = %d\n", a, b, div);
	printf("%d %% %d = %d \n\n", a, b, mod);
	*/

	/*	EXERCICE 4		*/
	/*
	int	a;
	int	b;

	a = 10;
	b = 3;
	ft_ultimate_div_mod(&a, &b);
	printf("Les résultats sont: %d et %d\n\n", a, b);
	*/

	/*	EXERCICE 5&6	*/
	/*
	char *str;
	str = "";
	ft_putstr(str);
	printf("\n%d\n", ft_strlen(str));
	*/

	/*	EXERCICE 7		*/
	/*
	char	str[] = "RUOJNOB";

	printf("%s\n", str);
	printf("%s\n", ft_strrev(str));
	printf("%s\n", str);
	*/

	/*	EXERCICE 8		*/
	/*
	int tab[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int size;
	int i;

	size = 10;
	i = 0;
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	ft_sort_integer_table(tab, size);
	i = 0;
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	*/

	/*	EXERCICE 9		*/

	char str[14] = {"@@-1,8+1,8@@$"};
	printf("%s -> %d\n", str, ft_atoi(str));
	printf("%s -> %d\n\n", str, atoi(str));

	char str1[7] = {"+0200$"};
	printf("%s -> %d\n", str, ft_atoi(str1));
	printf("%s -> %d\n\n", str, atoi(str1));

	char str2[12] = {"-2147483648"};
	printf("%s -> %d\n", str, ft_atoi(str2));
	printf("%s -> %d\n\n", str, atoi(str2));

	char str3[3] = {"21"};
	printf("%s -> %d\n", str, ft_atoi(str3));
	printf("%s -> %d\n\n", str, atoi(str3));

	char str4[2] = {"0"};
	printf("%s -> %d\n", str, ft_atoi(str4));
	printf("%s -> %d\n\n", str, atoi(str4));

	char str5[3] = {"-0"};
	printf("%s -> %d\n", str, ft_atoi(str5));
	printf("%s -> %d\n\n", str, atoi(str5));

	char str6[8] = {"1000000"};
	printf("%s -> %d\n", str, ft_atoi(str6));
	printf("%s -> %d\n\n", str, atoi(str6));

	char str7[10] = {"709551615"};
	printf("%s -> %d\n", str, ft_atoi(str7));
	printf("%s -> %d\n\n", str, atoi(str7));

	char str8[6] = {"0$"};
	printf("%s -> %d\n", str, ft_atoi(str8));
	printf("%s -> %d\n\n", str, atoi(str8));

	char str9[6] = {"0$"};
	printf("%s -> %d\n", str, ft_atoi(str9));
	printf("%s -> %d\n\n", str, atoi(str9));

	char str10[6] = {"0$"};
	printf("%s -> %d\n", str, ft_atoi(str10));
	printf("%s -> %d\n\n", str, atoi(str10));

	char str11[6] = {"0$"};
	printf("%s -> %d\n", str, ft_atoi(str11));
	printf("%s -> %d\n\n", str, atoi(str11));

	char str12[6] = {"0$"};
	printf("%s -> %d\n", str, ft_atoi(str12));
	printf("%s -> %d\n\n", str, atoi(str12));

}
