/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:55:19 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/08 14:34:17 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*pd;
	unsigned char	*ps;

	pd = (unsigned char*)dst;
	ps = (unsigned char*)src;
	if (ps < pd)
	{
		i = (int)(n - 1);
		while (i >= 0)
		{
			pd[i] = ps[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while ((size_t)i < n)
		{
			pd[i] = ps[i];
			i++;
		}
	}
	return (dst);
}
