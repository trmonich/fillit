/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:15:22 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/13 20:38:46 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*end_dst;
	size_t	i;
	size_t	dst_size;

	i = 0;
	end_dst = dst;
	while (*end_dst && i < size)
	{
		end_dst++;
		i++;
	}
	if (i == size || *end_dst != 0)
		return (size + ft_strlen(src));
	dst_size = i;
	i = 0;
	while (src[i] && i < size - dst_size - 1)
	{
		end_dst[i] = src[i];
		i++;
	}
	end_dst[i] = 0;
	return (dst_size + ft_strlen(src));
}
