/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 18:22:36 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 19:05:41 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*ft_lstfindfd(t_list *fd_list, size_t fd)
{
	t_list	*cur;

	if (fd_list == NULL)
		return (NULL);
	cur = fd_list;
	while (cur != NULL)
	{
		if (cur->content_size == fd)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

static void		ft_slicestr(t_list *cur, char **line, int *readc)
{
	char	*eol;
	char	*temp;

	temp = cur->content;
	eol = ft_strchr(temp, '\n');
	*line = ft_strsub(temp, 0, (eol - temp));
	cur->content = ft_strdup(eol + 1);
	free(temp);
	*readc = 1;
}

static int		ft_readfile(t_list *cur, const int fd, char **line, char *buf)
{
	int		rc;
	char	*temp;
	char	*eol;

	rc = 0;
	eol = ft_strchr(cur->content, '\n');
	while (eol == NULL && (rc = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rc] = '\0';
		if ((temp = ft_strjoin(cur->content, buf)) == NULL)
			return (-1);
		ft_strdel((char **)&(cur->content));
		cur->content = temp;
		eol = ft_strchr(buf, '\n');
	}
	if (rc >= 0 && eol)
		ft_slicestr(cur, line, &rc);
	else if (rc == 0 && ((char *)cur->content)[0] == 0)
		return (0);
	else if (rc >= 0 && (rc = 1))
	{
		*line = cur->content;
		cur->content = NULL;
	}
	return (rc);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*fd_list = NULL;
	t_list			*cur;
	int				readc;
	char			buf[BUFF_SIZE + 1];

	readc = 0;
	if (fd < 0 || line == NULL || (read(fd, buf, 0)) < 0)
		return (-1);
	if ((cur = ft_lstfindfd(fd_list, fd)) == NULL)
	{
		ft_lstadd(&fd_list, ft_lstnew("", fd));
		if (fd_list == NULL)
			return (-1);
		cur = ft_lstfindfd(fd_list, fd);
	}
	if (cur->content)
		readc = ft_readfile(cur, fd, line, buf);
	else
		readc = 0;
	if (readc <= 0)
	{
		ft_lstremove(&fd_list, &cur, &ft_lststrdel);
		return (readc);
	}
	return (1);
}
