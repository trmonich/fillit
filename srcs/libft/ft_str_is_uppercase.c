/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 21:13:14 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/14 11:41:01 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_uppercase(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] >= 'A' && str[i] <= 'Z')
		i++;
	if (i < ft_strlen(str))
		return (0);
	return (1);
}
