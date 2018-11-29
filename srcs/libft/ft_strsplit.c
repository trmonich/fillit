/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:29:31 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/10 14:53:23 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	j = 0;
	count = 0;
	while (s[++i])
	{
		if (s[i] != c && j == 0)
		{
			j = 1;
			++count;
		}
		else if (s[i] == c)
			j = 0;
	}
	return (count);
}

static int	word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**stock_word(char const *s, char **str_tab, char c)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = -1;
	while (++y < count_word(s, c))
	{
		x = 0;
		while (s[i] && s[i] == c)
			i++;
		if (!(str_tab[y] = (char *)malloc(sizeof(char) *
						(word_len(&s[i], c) + 1))))
			return (NULL);
		while (s[i] && s[i] != c)
		{
			str_tab[y][x] = s[i];
			x++;
			i++;
		}
		str_tab[y][x] = '\0';
	}
	return (str_tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str_tab;

	if (s)
	{
		if (!(str_tab = (char **)malloc(sizeof(char *) * count_word(s, c) + 1)))
			return (NULL);
		str_tab[count_word(s, c)] = 0;
		str_tab = stock_word(s, str_tab, c);
		return (str_tab);
	}
	return (NULL);
}
