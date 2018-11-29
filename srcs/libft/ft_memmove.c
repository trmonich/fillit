/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 09:38:12 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/08 18:41:28 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	if (src_ptr < dst_ptr && src_ptr + len > dst_ptr)
	{
		i = len;
		while (i > 0)
		{
			--i;
			dst_ptr[i] = src_ptr[i];
		}
	}
	else
	{
		i = -1;
		while (++i < len)
			dst_ptr[i] = src_ptr[i];
	}
	return (dst);
}
