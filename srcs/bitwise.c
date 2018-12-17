/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:29:56 by trmonich          #+#    #+#             */
/*   Updated: 2018/12/14 15:00:13 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_bit(unsigned int *tab, int k, int side)
{
	tab[k / side] |= 1 << (k % side);
}

void	clear_bit(unsigned int *tab, int k, int side)
{
	tab[k / side] &= ~(1 << (k % side));
}

int		test_bit(unsigned int *tab, int k, int side)
{
	return ((tab[k / side] & (1 << (k % side))) != 0);
}
