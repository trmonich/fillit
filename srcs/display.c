/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:26:39 by trmonich          #+#    #+#             */
/*   Updated: 2018/12/17 17:44:14 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	map_free(char **map)
{
	int		i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

static char	**map_alloc(int side)
{
	char	**new_map;
	int		i;

	if (!(new_map = (char**)malloc(sizeof(char*) * (side + 1))))
		return (NULL);
	new_map[side] = 0;
	i = 0;
	while (i < side)
	{
		new_map[i] = ft_strnew(side);
		ft_memset(new_map[i], (int)'.', side);
		i++;
	}
	return (new_map);
}

int			display(int side, t_piece *pool)
{
	int		pos;
	char	**map;
	int		k;
	t_point	point;

	point.letter = 'A';
	if (!(map = map_alloc(side)))
		return (0);
	while (pool->len != 0)
	{
		k = -1;
		pos = pool->pos;
		while (++k < 16)
			if (test_bit(pool->shape, k, 4))
			{
				point.x = pos / side + k / 4;
				point.y = pos % side + k % 4;
				map[point.x][point.y] = point.letter;
			}
		pool++;
		point.letter++;
	}
	ft_show_table(map);
	map_free(map);
	return (1);
}
