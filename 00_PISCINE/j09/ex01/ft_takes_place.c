/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_takes_place.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 19:13:28 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 19:56:50 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>

void	first_cases(int hour)
{
	if (hour == 0)
		printf("THE FOLLOWING TAKES PLACE BETWEEN 12.00 A.M. AND 1.00 A.M.\n");
	else
	{
		printf("THE FOLLOWING TAKES PLACE BETWEEN ");
		printf("%d.00 A.M. AND %d.00 A.M.\n", hour, (hour + 1));
	}
}

void	second_cases(int hour)
{
	if (hour == 11)
		printf("THE FOLLOWING TAKES PLACE BETWEEN 11.00 A.M. AND 12.00 P.M.\n");
	else
	{
		printf("THE FOLLOWING TAKES PLACE BETWEEN 12.00 P.M. AND 1.00 P.M.\n");
	}
}

void	third_cases(int hour)
{
	if (hour > 12 && hour < 23)
	{
		printf("THE FOLLOWING TAKES PLACE BETWEEN ");
		printf("%d.00 P.M. AND %d.00 P.M.\n", (hour % 12), (hour % 12 + 1));
	}
	else
	{
		printf("THE FOLLOWING TAKES PLACE BETWEEN 11.00 P.M. AND 12.00 A.M.\n");
	}
}

void	last_case(int hour)
{
	printf("THE FOLLOWING TAKES PLACE BETWEEN 12.00 A.M. AND 1.00 A.M.\n");
}

void	ft_takes_place(int hour)
{
	if (hour == 0 || (hour > 1 && hour < 11))
		first_cases(hour);
	else if (hour == 11 || hour == 12)
		second_cases(hour);
	else if ((hour > 12 && hour < 23) || hour == 23)
		third_cases(hour);
	else if (hour == 24)
		last_case(hour);
}
