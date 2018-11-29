/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:53:26 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/13 18:17:22 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	i = -1;
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	while (++i < n)
	{
		dst_ptr[i] = src_ptr[i];
		if (src_ptr[i] == (unsigned char)c)
			return (&dst[i + 1]);
	}
	return (NULL);
}
