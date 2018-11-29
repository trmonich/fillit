/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 20:58:58 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/14 11:41:47 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_numeric(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i < ft_strlen(str))
		return (0);
	return (1);
}
