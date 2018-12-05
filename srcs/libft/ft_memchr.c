/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:54:21 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/08 19:07:05 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_ptr;

	i = -1;
	s_ptr = (unsigned char *)s;
	while (++i < n)
		if (s_ptr[i] == (unsigned char)c)
			return (&s_ptr[i]);
	return (NULL);
}
