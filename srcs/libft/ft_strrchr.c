/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:02:08 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/07 11:13:27 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*match;

	i = 0;
	match = NULL;
	while (s[i])
	{
		if (s[i] == c)
			match = (char *)&s[i];
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (match);
}
