/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:06:45 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/08 12:59:01 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;

	i = 0;
	if (*needle == 0)
		return ((char*)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			while (haystack[i] == needle[i] && haystack[i])
				i++;
			if (needle[i] == 0)
				return ((char*)haystack);
		}
		haystack++;
	}
	return (NULL);
}
