/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:54:33 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/29 09:18:06 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	int		i;
	char	*str;

	i = -1;
	if (!(str = (char *)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	while (src[++i])
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}
