/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 10:04:56 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/10 12:00:10 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t			i;
	unsigned int	start;
	char			*str;

	if (s)
	{
		i = 0;
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
			++i;
		start = i;
		while (s[i])
			++i;
		--i;
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i > 0)
			--i;
		if (!(str = ft_strsub(s, start, (start < i) ? i - start + 1 : 0)))
			return (NULL);
		return (str);
	}
	return (NULL);
}
