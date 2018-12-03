/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:08:17 by alesteph          #+#    #+#             */
/*   Updated: 2018/12/03 10:23:11 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static int	display_error(char *str)
{
	if (ft_strcmp(str, "wrong tetri") == 0)
		ft_putendl_fd("Tetriminos is/are not valid", 2);
	return (-1);
}

int			fillit(int fd)
{
	char	buffer[22];

	while (read(fd, buffer, 21) > 0)
	{
		buffer[21] = '\0';
		if (check_tetri(buffer) < 0)
			return (display_error("wrong tetri"));
	}
	return (0);
}
