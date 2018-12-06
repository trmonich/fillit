/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:41:33 by alesteph          #+#    #+#             */
/*   Updated: 2018/12/06 10:02:55 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		calcul(t_list *list)
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
