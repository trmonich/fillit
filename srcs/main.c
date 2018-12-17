/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:21:14 by alesteph          #+#    #+#             */
/*   Updated: 2018/12/17 17:44:50 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <string.h>

static void	fillit(int fd)
{
	int				i;
	int				side;
	unsigned int	*res;
	unsigned int	map[32];
	t_piece			*pool;

	i = -1;
	while (++i < 32)
		map[i] = 0;
	if (!(pool = read_pieces(fd)))
	{
		ft_putstr("error\n");
		return ;
	}
	side = get_side(pool);
	while ((res = find_solution(pool, map, side)) == NULL)
		++side;
	if (!(display(side, pool)))
		ft_putstr("error\n");
	free(pool);
}

int			main(int ac, char **av)
{
	int	fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		fillit(fd);
		close(fd);
	}
	else
		ft_putstr("usage: ./fillit tetri_file\n");
	return (0);
}
