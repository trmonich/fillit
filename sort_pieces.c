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

t_list	*sort_pieces(t_list *list, char *map, int map_size)
{
	static int num_piece = 0;
	int		i;
	t_piece	*piece;
	t_list	*buff;
	t_list	*poss_answer;

	i = 0;

	buff = go_to_index // a faire
	while (i < min(map_size - piece->wide - 1, map_size - 4 * (piece->length - 1)))
	{
		if (do_fit(piece, &map)) // change la map en meme temps
		{
			++num_piece;
			poss_ans = sort_pieces(list, map, map_size);
			if (size(poss_ans) < size(answer)) // gaffe qu cas ou non viable car pas fini
				answer = poss_ans;
		}
		i++;
	}
	--num_piece;
	return (first_link) // reflechir
}
