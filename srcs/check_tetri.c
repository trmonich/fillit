/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 09:59:09 by alesteph          #+#    #+#             */
/*   Updated: 2018/12/03 10:08:08 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_tetri(char *buffer)
{
	int	i;
	int	lines;
	int	hashtag;

	i = -1;
	lines = 0;
	hashtag = 0;
	while (buffer[++i])
	{
		if (buffer[i] == '\n')
			lines++;
		else if (buffer[i] == '#')
			hashtag++;
	}
	if (lines != 5 || hashtag != 4)
		return (-1);
	return (0);
}
