/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:07:28 by alesteph          #+#    #+#             */
/*   Updated: 2018/12/06 17:53:44 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*create_map(int size)
{
	int		total_len;
	char	*map;

	total_len = ((size * size) % 8 != 0) ? ((size * size) / 8) + 1 :
		(size * size) / 8;
	if (!(map = (char *)malloc(sizeof(char) * total_len)))
		return (NULL);
	return (map);
}
