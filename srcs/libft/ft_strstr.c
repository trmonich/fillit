/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:24:51 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/08 11:31:37 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	save;

	i = 0;
	while (s1[i])
	{
		j = 0;
		save = i;
		while (s1[i] == s2[j])
		{
			if (j >= (ft_strlen(s2) - 1))
				return ((char *)&s1[save]);
			j++;
			i++;
		}
		i = save;
		i++;
	}
	return (s2[0] == 0 ? (char *)s1 : NULL);
}
