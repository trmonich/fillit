/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:15:15 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/08 13:02:07 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == 0)
		return ((char*)haystack);
	while (*haystack && j < len)
	{
		if (*haystack == *needle)
		{
			while (haystack[i] == needle[i] && haystack[i] && (j + i) < len)
				i++;
			if (needle[i] == 0)
				return ((char*)haystack);
			i = 0;
		}
		haystack++;
		j++;
	}
	return (NULL);
}
