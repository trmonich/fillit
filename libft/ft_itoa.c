/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:07:30 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/12 11:55:37 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size_str(unsigned int n)
{
	size_t	size;

	size = 1;
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static void		ft_create_str(char *str, size_t size, unsigned int n)
{
	size_t	i;

	i = size - 1;
	while (i)
	{
		str[i] = n % 10 + 48;
		n = (n - n % 10) / 10;
		i--;
	}
	str[0] = n + 48;
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			size;

	size = ft_size_str(n < 0 ? -n : n);
	if (!(str = n < 0 ? ft_strnew(size + 1) : ft_strnew(size)))
		return (NULL);
	if (n < 0)
	{
		*str = '-';
		str++;
	}
	ft_create_str(str, size, n < 0 ? -n : n);
	return (n < 0 ? str - 1 : str);
}
