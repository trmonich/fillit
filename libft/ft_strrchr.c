/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:47:22 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/07 13:09:12 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		last_position;
	int		i;

	i = 0;
	last_position = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			last_position = i;
		i++;
	}
	if (c == 0)
		return ((char*)&(s[i]));
	return (last_position < 0 ? NULL : (char*)&(s[last_position]));
}
