/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_alesteph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:18:28 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/30 11:58:57 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <string.h>

void	check_tetri(char *buffer)
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
		ft_putendl_fd("Tetriminos file is not valid", 2);
	else
		ft_putendl("Tetriminos file is valid");
}

int		main(int ac, char **av)
{
	int		fd;
	char	buffer[22];

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while(read(fd, buffer, 21) > 0)
		{
			buffer[21] = '\0';
			check_tetri(buffer);
		}
		close(fd);
	}
	else
		ft_putstr_fd("usage: ./fillit file_name\n", 2);
	return (0);
}
