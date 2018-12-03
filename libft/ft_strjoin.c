/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:00:23 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/12 12:37:32 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*copy;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	copy = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (*s1)
	{
		copy[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		copy[i++] = *s2;
		s2++;
	}
	copy[i] = 0;
	return (copy);
}
