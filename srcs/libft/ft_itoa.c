/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:02:52 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/12 10:06:12 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(unsigned int n)
{
	int i;

	i = (n == 0) ? 1 : 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int				i;
	int				sign;
	unsigned int	nb;
	char			*str;

	sign = (n < 0) ? 1 : 0;
	nb = (n < 0) ? n * -1 : n;
	i = (n < 0) ? num_len(nb) : num_len(nb) - 1;
	if (!(str = (char *)malloc(sizeof(char) * (num_len(nb) + sign + 1))))
		return (NULL);
	if (sign == 1 || n == 0)
		str[0] = (n == 0) ? '0' : '-';
	str[i + 1] = '\0';
	while (nb > 0)
	{
		str[i] = (nb % 10) + 48;
		nb = nb / 10;
		--i;
	}
	return (str);
}
