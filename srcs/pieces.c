/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:36:21 by trmonich          #+#    #+#             */
/*   Updated: 2018/12/07 13:10:00 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		size_of_side(t_list *list)
{
	t_piece *piece;
	int	height;
	int	width;

	height = 0;
	width = 0;
	while (list)
	{
		piece = list->content;
		height += piece->length;
		width += piece->wide;
		list = list->next;
	}
	return ((height > width) ? height : width);
}

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
}

t_piece *new_piece(unsigned short shape)
{
	t_piece		*piece;

	piece = ft_memalloc(sizeof(*piece));
	piece->shape = shape;
	size(piece);
	return (piece);
}
