/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/10 03:52:00 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/10 04:17:55 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		s_len(char *str)
{
	int	cpt;

	cpt = 0;
	while (str[cpt] != '\0')
		cpt++;
	return (cpt);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int size_dest;

	size_dest = s_len(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i + size_dest] = src[i];
		i++;
	}
	dest[i + size_dest] = '\0';
	return (dest);
}
