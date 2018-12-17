/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:29:55 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/08 13:18:39 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *u1;
	unsigned char *u2;

	u1 = (unsigned char*)s1;
	u2 = (unsigned char*)s2;
	while (*u1 == *u2 && *u1)
	{
		u1++;
		u2++;
	}
	return (*u1 - *u2);
}
