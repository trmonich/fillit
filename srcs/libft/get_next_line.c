/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:07:36 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/29 15:03:01 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				return_error(char **tmp)
{
	free(*tmp);
	return (-1);
}

static t_list	*get_fd(t_list **fd_list, int fd)
{
	t_list	*temp;

	temp = *fd_list;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	if (!(temp = ft_lstnew("\0", fd)))
		return (NULL);
	ft_lstadd(fd_list, temp);
	return (temp);
}

int				to_line(char **s, char **line)
{
	char	*tmp;

	if (ft_strlen(*s) && !ft_strstr(*s, "\n"))
	{
		tmp = *line;
		if (!(*line = ft_strdup(*s)))
			return (return_error(&tmp));
		free(tmp);
		ft_strclr(*s);
		return (1);
	}
	else if (ft_strlen(*s))
	{
		tmp = *line;
		if (!(*line = ft_strndup(*s,
			ft_strstr(*s, "\n") - (char*)(*s))))
			return (return_error(&tmp));
		free(tmp);
		tmp = *s;
		if (!(*s = ft_strdup(ft_strstr(*s, "\n") + 1)))
			return (return_error(&tmp));
		free(tmp);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*fd_list;
	t_list			*elem;
	int				nb;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0 ||
			!(*line = ft_strnew(1)))
		return (-1);
	if (!(elem = get_fd(&fd_list, fd)))
		return (return_error(&tmp));
	while (!ft_strstr(elem->content, "\n") && (nb = read(fd, buff, BUFF_SIZE)))
	{
		buff[nb] = 0;
		tmp = elem->content;
		if (!(elem->content = ft_strjoin(tmp, buff)))
			return (return_error(&tmp));
		free(tmp);
	}
	return (to_line((char**)&(elem->content), line));
}
