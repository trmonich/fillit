/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 09:05:39 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/10 09:15:05 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	if (s && f)
	{
		if (!(str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		i = -1;
		while (s[++i])
			str[i] = (*f)(i, s[i]);
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
