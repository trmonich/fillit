/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:43:38 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/13 21:31:15 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcapitalize(char *str)
{
	char *s;

	if (!str)
		return (NULL);
	s = str;
	while (*s != '\0')
	{
		while (!ft_isalnum(*s))
		{
			s++;
			if (*s == '\0')
				return (str);
		}
		if (*s >= 'a' && *s <= 'z')
			*s = *s - 32;
		s++;
		while (ft_isalnum(*s))
		{
			if (*s >= 'A' && *s <= 'Z')
				*s = *s + 32;
			s++;
		}
	}
	return (str);
}
