/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strupcase.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/10 01:53:00 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/10 19:51:23 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		is_letter_or_number(char c)
{
	if (c < 48 || (c > 57 && c < 65) || (c > 90 && c < 97) || (c > 122))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int treated_word;

	treated_word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!treated_word && is_letter_or_number(str[i]))
		{
			treated_word = 1;
			if (str[i] >= 97 && str[i] <= 122)
				str[i] -= 32;
		}
		else if (treated_word && is_letter_or_number(str[i]))
		{
			if (str[i] >= 65 && str[i] <= 90)
				str[i] += 32;
		}
		else if (treated_word && !is_letter_or_number(str[i]))
			treated_word = 0;
		i++;
	}
	return (str);
}
