/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 09:39:54 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/10 09:47:16 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (s)
	{
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		i = -1;
		while (++i < len)
			str[i] = s[i + start];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
