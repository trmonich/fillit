/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:11:31 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/29 10:45:22 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		end_of_line(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

static char		*send_line(t_list *lst, int n)
{
	char	*str;
	char	*save;
	int		end;

	end = (n == -1) ? ft_strlen(lst->content) : n;
	str = ft_strsub(lst->content, 0, end);
	if (n == -1)
		lst->content[0] = '\0';
	else
	{
		save = lst->content;
		lst->content = ft_strdup(lst->content + end + 1);
		free(save);
	}
	return (str);
}

static t_list	*lst_select(int fd)
{
	static	t_list	*lst = NULL;
	t_list			*fd_select;

	if (!lst)
		lst = ft_lstnew("", fd);
	fd_select = lst;
	while (fd_select->content_size != (size_t)fd)
	{
		if (!fd_select->next)
			fd_select->next = ft_lstnew("", fd);
		fd_select = fd_select->next;
	}
	return (fd_select);
}

int				get_next_line(const int fd, char **line)
{
	int		rd;
	char	*tmp;
	t_list	*lst;
	char	buffer[BUFF_SIZE + 1];

	if (fd < 0 || BUFF_SIZE < 0 || (rd = read(fd, buffer, 0)) < 0)
		return (-1);
	lst = lst_select(fd);
	while (!ft_strchr(lst->content, '\n') &&
			(rd = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[rd] = '\0';
		tmp = lst->content;
		lst->content = ft_strjoin(lst->content, buffer);
		free(tmp);
	}
	if (ft_isempty(lst->content) != 0)
	{
		if (!(*line = send_line(lst, end_of_line(lst->content))))
			return (-1);
		return (1);
	}
	return (0);
}
