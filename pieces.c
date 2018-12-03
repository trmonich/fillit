/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:36:21 by trmonich          #+#    #+#             */
/*   Updated: 2018/12/03 11:53:31 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void	size(t_piece *piece)
{
	int				i;
	unsigned long	test;

	test = (*piece).shape;
	i = 0;
	while (test)
	{
		i++;
		test = test << 1;
	}
	(*piece).length = i / 4 + 1;
	(*piece).wide = i % 4 + 1;
}

t_piece *new_piece(unsigned short shape)
{
	t_piece		*piece;

	piece = ft_memalloc(sizeof(*piece));
	piece->shape = shape;
	size(piece);
	return (piece);
}
