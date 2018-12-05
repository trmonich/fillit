/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:49:29 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/14 11:03:13 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int i;
	int capitalize;

	i = 0;
	capitalize = 1;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if ((str[i] < 'a' || str[i] > 'z') && (str[i] < '0' || str[i] > '9'))
			capitalize = 1;
		else if (capitalize == 1)
		{
			str[i] = (str[i] < '0' || str[i] > '9') ? str[i] - 32 : str[i];
			capitalize = 0;
		}
		i++;
	}
	return (str);
}
