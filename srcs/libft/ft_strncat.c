/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:09:21 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/07 13:07:00 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*end_s1;
	size_t	i;

	i = 0;
	end_s1 = s1;
	while (*end_s1)
		end_s1++;
	while (s2[i] && i < n)
	{
		end_s1[i] = s2[i];
		i++;
	}
	end_s1[i] = 0;
	return (s1);
}
