/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:37:57 by alesteph          #+#    #+#             */
/*   Updated: 2018/12/17 17:35:55 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <fcntl.h>

static void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
}

t_piece		*read_pieces(int fd)
{
	char	**tab;
	char	buff[BUFF_SIZE + 1];
	t_piece *pool;
	int		ret;
	size_t	i;

	i = 0;
	if (!(pool = (t_piece*)malloc(sizeof(t_piece) * 27)))
		return (NULL);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = 0;
		tab = ft_strsplit(buff, '\n');
		if (!check_validity(tab))
			return (NULL);
		pool[i] = new_piece(tab);
		free_tab(tab);
		if (read(fd, buff, 1) && *buff != '\n')
			return (NULL);
		i++;
	}
	if (buff[0] == '\n' || i == 0)
		return (NULL);
	pool[i].len = 0;
	return (pool);
}
