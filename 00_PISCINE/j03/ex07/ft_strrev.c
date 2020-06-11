/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/06 09:31:12 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/06 14:33:18 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		cpt;
	int		cpt_bis;
	char	c;

	cpt = 0;
	cpt_bis = 0;
	while (str[cpt] != '\0')
		cpt++;
	cpt--;
	while (cpt_bis < cpt)
	{
		c = str[cpt];
		str[cpt] = str[cpt_bis];
		str[cpt_bis] = c;
		cpt--;
		cpt_bis++;
	}
	return (str);
}
