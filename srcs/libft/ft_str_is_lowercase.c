/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 21:06:56 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/14 11:41:17 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_lowercase(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] >= 'a' && str[i] <= 'z')
		i++;
	if (i < ft_strlen(str))
		return (0);
	return (1);
}
