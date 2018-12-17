/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:43:07 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/06 17:49:33 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n && ((unsigned char*)s1)[i] == ((unsigned char*)s2)[i])
		i++;
	if (i == n)
		return (0);
	else
		return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
