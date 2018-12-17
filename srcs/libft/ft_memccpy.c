/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:35:43 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/13 21:16:02 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ps;
	unsigned char	*pd;

	ps = (unsigned char*)src;
	pd = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		pd[i] = ps[i];
		if (ps[i] == (unsigned char)c)
			return (&pd[i + 1]);
		i++;
	}
	return (NULL);
}
