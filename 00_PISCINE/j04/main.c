/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/07 10:36:12 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/07 20:53:43 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include	<stdio.h>
#include	<time.h>

int		ft_iterative_factorial(int nb);
int		ft_recursive_factorial(int nb);
int		ft_iterative_power(int nb, int power);
int		ft_recursive_power(int nb, int power);
int		ft_fibonacci(int index);
int		ft_sqrt(int nb);
int		ft_is_prime(int nb);
int		ft_find_next_prime(int nb);
void	ft_eight_queens_puzzle(void);


int		main(void)
{
	/*	EXERCICE 1	*/
	/*
	//clock_t begin = clock();
	int n;

	n = -5;
	printf("%d! = %d\n", n, ft_iterative_factorial(n));
	printf("%d! = %d\n", n, ft_recursive_factorial(n));

	//	TIME EVALUATION
	//clock_t end = clock();
	//double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	//printf("%f sec\n", time_spent);
	*/
	
	/*	EXERCICE 2	*/
	//clock_t begin = clock();
	/*
	int n;
	int pow;

	n = -2;
	pow = 29;
	printf("%d\n", ft_iterative_power(n, pow));

	//clock_t end = clock();
	//double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	//printf("%f sec\n", time_spent);

	printf("%d\n", ft_recursive_power(n, pow));
	*/

	/*	EXERCICE 4	*/
	/*
	int nb = 16 ;
	printf("fibo[%d] = %d\n", nb, ft_fibonacci(nb));
	*/

	/*	EXERCICE 5	*/
	/*
	int nb = 4;
	clock_t begin = clock();
	printf("sqrt(%d) = %d\n", nb, ft_sqrt(nb));
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time = %f sec\n", time_spent);
	*/

	/*	EXERCICE 6	*/
	/*
	int	nb = 2147483647;
	if (ft_is_prime(nb))
		printf("%d est premier!\n", nb);
	else
		printf("%d n'est pas premier...\n", nb);
	*/

	/*	EXERCICE 7	*/
	/*
	int nb = 2147483647;
	printf("Le premier immediatement superieur a %d est %d.\n", nb, ft_find_next_prime(nb));
	*/

	/*	EXERCICE 8	*/

	ft_eight_queens_puzzle();

	return (0);
}
