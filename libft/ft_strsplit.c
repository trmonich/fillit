/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:49:56 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/12 12:49:56 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_is_sep(char const *str, char c)
{
	if (*str && *str != c)
		return (0);
	else
		return (1);
}

static int	ft_word_size(char const *str, char c)
{
	int i;

	i = 0;
	while (!ft_is_sep(str, c))
	{
		i++;
		str++;
	}
	return (i);
}

static int	ft_count_word(char const *str, char c)
{
	int count;

	count = 0;
	if (!ft_is_sep(str, c))
		count++;
	while (*str)
	{
		if (ft_is_sep(str, c) && !ft_is_sep(str + 1, c))
			count++;
		str++;
	}
	return (count);
}

static void	ft_find_positions(int **where, int nb_w, char const *str, char c)
{
	int i;
	int j;

	i = 1;
	j = 1;
	if (!ft_is_sep(str++, c))
		(*where)[0] = 0;
	else
		j--;
	while (j < nb_w)
	{
		if (!ft_is_sep(str, c) && ft_is_sep(str - 1, c))
		{
			(*where)[j] = i;
			j++;
		}
		str++;
		i++;
	}
}

char		**ft_strsplit(char const *str, char c)
{
	int		*where;
	char	**tab;
	int		i[2];
	char	*s;

	if (!str)
		return (NULL);
	if (!(where = malloc(sizeof(int) * ft_count_word(str, c))))
		return (NULL);
	ft_find_positions(&where, ft_count_word(str, c), str, c);
	if (!(tab = malloc(sizeof(*tab) * (ft_count_word(str, c) + 1))))
		return (NULL);
	i[0] = -1;
	while (++(i[0]) < ft_count_word(str, c))
	{
		s = (char*)(str + where[i[0]]);
		if (!(tab[i[0]] = malloc(sizeof(char) * (ft_word_size(s, c) + 1))))
			return (NULL);
		i[1] = -1;
		while (!ft_is_sep(&s[++i[1]], c))
			tab[i[0]][i[1]] = s[i[1]];
		tab[i[0]][i[1]] = 0;
	}
	tab[i[0]] = 0;
	return (tab);
}
