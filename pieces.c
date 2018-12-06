/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:36:21 by trmonich          #+#    #+#             */
/*   Updated: 2018/12/06 17:40:24 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void	size(t_piece *piece)
{
	unsigned short	mask;
	unsigned short	test;

	test = piece->shape;
	piece->wide = 0;
	mask = 0x8888;
	while (test != 0x0)
	{
		test = test & (~mask);
		piece->wide++;
		mask = mask >> 1;
	}
	test = piece->shape;
	mask = 0xF000;
	piece->length = 0;
	while (test != 0x0)
	{
		test = test & (~mask);
		piece->length++;
		mask = mask >> 4;
	}
	printf("on a bien %d et %d\n", piece->length, piece->wide);
}

t_piece *new_piece(unsigned short shape)
{
	t_piece		*piece;

	piece = ft_memalloc(sizeof(*piece));
	piece->shape = shape;
	size(piece);
	printf("on a bien %d et %d en sortant\n", piece->length, piece->wide);
	return (piece);
}
