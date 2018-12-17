/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:50:11 by trmonich          #+#    #+#             */
/*   Updated: 2018/12/14 14:19:01 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	corner(t_piece *piece)
{
	int	i;
	int k;

	while (piece->shape[0] == 0)
	{
		i = 0;
		while (++i < 4)
			piece->shape[i - 1] = piece->shape[i];
		piece->shape[3] = 0;
		piece->len--;
	}
	i = -1;
	k = 3;
	while (++i < 16)
		if (test_bit(piece->shape, i, 4) && (k > i % 4))
			k = i % 4;
	i = 0;
	while (i < 4)
		piece->shape[i++] >>= k;
	piece->wid -= k;
}

t_piece		new_piece(char **tab)
{
	int		k;
	t_piece	piece;

	piece.wid = 1;
	piece.len = 1;
	piece.pos = -1;
	k = 0;
	while (k < 4)
		piece.shape[k++] = 0;
	k = 0;
	while (k < 16)
	{
		if (tab[k / 4][k % 4] == '#')
		{
			set_bit(piece.shape, k, 4);
			if (k / 4 > piece.len - 1)
				piece.len = k / 4 + 1;
			if (k % 4 > piece.wid - 1)
				piece.wid = k % 4 + 1;
		}
		k++;
	}
	corner(&piece);
	return (piece);
}
