/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 21:38:33 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/14 11:40:48 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_printable(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] >= 32 && str[i] <= 126)
		i++;
	if (i < ft_strlen(str))
		return (0);
	return (1);
}
