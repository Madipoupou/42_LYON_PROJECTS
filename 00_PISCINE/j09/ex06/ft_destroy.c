/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_destroy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/13 01:47:15 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/13 01:48:49 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_destroy(char ***factory)
{
	int i;
	int j;
	int k;

	i = 0;
	while (factory[i] != NULL)
	{
		j = 0;
		while (factory[i][j] != NULL)
		{
			k = 0;
			while (factory[i][j][k] != NULL)
			{
				free(factory[i][j][k]);
				k++;
			}
			free(factory[i][j]);
			j++;
		}
		free(factory[i]);
		i++;
	}
}
