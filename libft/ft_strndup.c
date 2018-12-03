/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 09:32:55 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/16 12:46:41 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char		*copy;
	size_t		i;

	i = 0;
	copy = (char*)malloc(sizeof(char) * (n > ft_strlen(s1) ?
				ft_strlen(s1) + 1 : n + 1));
	if (!copy)
		return (NULL);
	while (s1[i] && i < n)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}
