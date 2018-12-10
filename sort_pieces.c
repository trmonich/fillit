/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pieces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 08:49:45 by trmonich          #+#    #+#             */
/*   Updated: 2018/12/07 17:11:13 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	do_fit(t_piece *piece, int pos, int *map[32], int map_size) // attention ici la map size est le cote, pas le cas en bas pour linstant
{
	int	shape[4];
	size_t	i;
	int	k;

	shape = piece->shape;
	if ((pos % map_size > map_size - piece->wide) || (pos / map_size > map_size - piece->length))
		return (0);
	i = 0;
	while (i < 4 && !shape[i])
	{
		k = pos / map_size + i;
		shape[i] = shape[i] >> pos % map_size;
		if (((shape[i] ^ map[k]) & map[k]) != map[k])
			return (0);
		map[k] = map[k] | shape[i];
		i++;
	}
	return (1);
}

0101 shape
1000 map

XOR donne 1101, ce quon veut a la fin // on peut XOR puis ET avec map, on recupere map si shape etait bon
inverse map XOR donne 0010 non


void	sort_pieces(int **tab, t_list *list, char *map, int map_size) // tab initialisé a NULL
{
	static int num_piece = 0;
	int		i;
	t_piece	*piece;
	int	*res;

	i = 0;

	piece = (ft_list_at(list, num_piece))->content;
	while (i < map_size * map_size) //cote du carre
	{
		res = (int*)malloc(sizeof(int) * ft_lstcount(list));
		res = *tab; //copie de tab ? prevoir si null
		if (do_fit(piece, i, &map, map_size)) // change la map en meme temps
		{
			res[num_piece] = i;
			if(num_piece == ft_lstcount(list))
			{
				++num_piece;
				sort_pieces(&res, list, map, map_size);
			}
		}
		i++;
		if (size(res, list) < size(*tab, list)) //prevoir si tab null ou pas complet
			*tab = res;
		else
			free(res);
	}
	--num_piece;
	return (tab) // reflechir
}
