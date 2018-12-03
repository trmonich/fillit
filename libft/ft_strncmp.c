/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:34:13 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/12 15:17:20 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*u1;
	unsigned char	*u2;

	u1 = (unsigned char*)s1;
	u2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (u1[i] == u2[i] && u1[i] && i < n - 1)
		i++;
	return (u1[i] - u2[i]);
}
