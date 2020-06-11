/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat2.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/10 18:53:23 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/10 19:19:25 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int				string_len(char *str)
{
	int cpt;

	cpt = 0;
	while (str[cpt] != '\0')
		cpt++;
	return (cpt);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*dest_cp;
	char			*src_cp;
	unsigned int	n;
	unsigned int	dest_len;

	dest_cp = dest;
	src_cp = src;
	n = size;
	while (n-- != 0 && *dest_cp != '\0')
		dest_cp++;
	dest_len = dest_cp - dest;
	n = size - dest_len;
	if (n == 0)
		return (dest_len + string_len(src));
	while (*src_cp != '\0')
	{
		if (n != 1)
		{
			*dest_cp++ = *src_cp;
			n--;
		}
		src_cp++;
	}
	*dest_cp = '\0';
	return (dest_len + (src_cp - src));
}
