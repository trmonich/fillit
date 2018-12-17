/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:11:59 by alesteph          #+#    #+#             */
/*   Updated: 2018/12/14 15:01:40 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				get_side(t_piece *pool)
{
	int	i;
	int	count;
	int	res;

	i = -1;
	count = 0;
	res = 2;
	while (pool[++i].len != 0)
		count++;
	while ((res * res) < count * 4)
		res++;
	return (res);
}

static int		is_fit(t_piece piece, int pos, unsigned int *map, int side)
{
	int	i;

	i = -1;
	if ((side - (pos % side) < piece.wid) ||
			(side - (pos / side) < piece.len))
		return (0);
	while (++i < 4)
	{
		if ((map[pos / side + i] & (piece.shape[i] << (pos % side))) != 0)
			return (0);
	}
	return (1);
}

static void		do_fit(t_piece *piece, int pos, unsigned int **map, int side)
{
	int	i;

	i = -1;
	piece->pos = pos;
	while (++i < 4)
		(*map)[pos / side + i] |= (piece->shape[i] << (pos % side));
}

static void		rev_fit(t_piece *piece, int pos, unsigned int **map, int side)
{
	int	i;

	i = -1;
	piece->pos = -1;
	while (++i < 4)
		(*map)[pos / side + i] &= ~(piece->shape[i] << (pos % side));
}

unsigned int	*find_solution(t_piece *pool, unsigned int *map, int map_size)
{
	static int		num = 0;
	int				k;
	unsigned int	*res;

	k = -1;
	if (pool[num].len == 0)
		return (map);
	while (++k < map_size * map_size)
	{
		if (is_fit(pool[num], k, map, map_size) == 1)
		{
			do_fit(&pool[num++], k, &map, map_size);
			if ((res = find_solution(pool, map, map_size)) != NULL)
				return (res);
			rev_fit(&pool[--num], k, &map, map_size);
		}
	}
	return (NULL);
}
