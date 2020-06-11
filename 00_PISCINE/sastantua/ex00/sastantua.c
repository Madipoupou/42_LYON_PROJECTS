/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sastantua2.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/08 06:39:21 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/08 21:10:52 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_putchar(char c);
int		series(int i, int type);
int		eval_length(int i);
void	disp_floor (int height, int length, int max_length, int size);
char	char_to_print(int size, int index[2], int height, int m_len);
void	sastantua(int size);

int		series(int i, int type)
{
	if (type == 0)
	{
		if (i == 0)
			return (1);
		if (i % 2 == 0)
			return (series((i - 1), type) + 1);
		else
			return (series((i - 1), type));
	}
	else
	{
		if (i == 1)
			return (1);
		if (i % 2 == 0)
			return (series((i - 1), type));
		else
			return (2 + series((i - 1), type));
	}
}

int		eval_length(int i)
{
	if (i == 0)
		return (7);
	if (i == 1)
		return (19);
	return (((3 + (i - 1)) + (series((3 + i), 0))) * 2 + eval_length(i - 1));
}

char	char_to_print(int size, int index[2], int height, int m_len)
{
	int door_size;
	int test;
	int test2;

	door_size = series(size, 1);
	test = (index[0] < (height - door_size));
	test = test || (index[1] < ((m_len - door_size) / 2));
	test = test || (index[1] > (((m_len + door_size) / 2) - 1));
	if (door_size < 5)
		test2 = 0;
	else
	{
		test2 = index[0] == (height - door_size) + (door_size / 2);
		test2 = test2 && index[1] == (((m_len + door_size) / 2 - 2));
	}
	if (test2)
		return ('$');
	else if (test)
		return ('*');
	else
		return ('|');
}

void	disp_floor(int height, int length, int m_len, int size)
{
	int	index[2];
	int	c_len;
	int is_last;

	is_last = (m_len == length);
	index[0] = -1;
	while (++index[0] < height)
	{
		c_len = length - (2 * (height - (index[0] + 1)));
		index[1] = -1;
		while (++index[1] < ((m_len - c_len) / 2))
			ft_putchar(' ');
		ft_putchar('/');
		while (++index[1] < ((m_len + c_len) / 2) - 1)
		{
			if (is_last)
				ft_putchar(char_to_print(size, index, height, m_len));
			else
				ft_putchar('*');
		}
		ft_putchar('\\');
		ft_putchar('\n');
	}
}

void	sastantua(int size)
{
	int i;
	int height;
	int length;
	int	max_length;

	height = 3;
	if (size <= 0)
		return ;
	i = 0;
	max_length = eval_length(size - 1);
	while (i < size)
	{
		length = eval_length(i);
		disp_floor(height, length, max_length, size);
		height++;
		i++;
	}
}
