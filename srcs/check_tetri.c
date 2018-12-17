/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 09:59:09 by alesteph          #+#    #+#             */
/*   Updated: 2018/12/17 09:32:02 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	pos_valid(char **tab, int i, int j)
{
	int	up;
	int	down;
	int	prev;
	int	next;
	int count;

	up = (i > 0) ? i - 1 : -1;
	down = (i < 3) ? i + 1 : -1;
	prev = (j > 0) ? j - 1 : -1;
	next = (j < 3) ? j + 1 : -1;
	count = 0;
	if (up >= 0 && tab[up][j] == '#')
		count++;
	if (down >= 0 && tab[down][j] == '#')
		count++;
	if (prev >= 0 && tab[i][prev] == '#')
		count++;
	if (next >= 0 && tab[i][next] == '#')
		count++;
	return (count);
}

int			check_link(char **tab)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == '#')
				count += pos_valid(tab, i, j);
		}
	}
	if (count <= 4)
		return (0);
	return (1);
}

int			check_validity(char **tab)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (tab[++i])
	{
		j = -1;
		if (ft_strlen(tab[i]) != 4)
			return (0);
		while (tab[i][++j])
		{
			if (tab[i][j] == '#')
				count++;
			else if (tab[i][j] != '.')
				return (0);
		}
	}
	if (i != 4 || count != 4 || !check_link(tab))
		return (0);
	return (1);
}
