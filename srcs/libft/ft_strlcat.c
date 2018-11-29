/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 13:15:23 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/08 11:20:06 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned long	i;
	unsigned long	nb;

	i = ft_strlen(dest);
	nb = (size < i) ? size + ft_strlen(src) : ft_strlen(dest) + ft_strlen(src);
	if (size <= 0)
		return (nb);
	while (i < size - 1 && *src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (nb);
}
