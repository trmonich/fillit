/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_alesteph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:18:28 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/29 16:28:22 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fillit.h"
#include <fcntl.h>
#include <string.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		get_next_line(fd, &line);
		close(fd);
	}
	else
		ft_putstr_fd("./fillit file_name\n", 2);
	return (0);
}
