/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:50:34 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/14 11:10:16 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_nbr(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (0);
}

static int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (ft_strlen(base) < 2)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-') ? -1 : 1;
	while (str[i] && str[i] != '+' && str[i] != '-')
		nb = nb * ft_strlen(base) + find_nbr(str[i++], base);
	return (nb * sign);
}

static void	convert_to_base_to(char **c, unsigned int nb, int index,
		char *base_to)
{
	if (nb >= (unsigned int)ft_strlen(base_to))
	{
		convert_to_base_to(c, nb / (unsigned int)ft_strlen(base_to),
				index - 1, base_to);
		convert_to_base_to(c, nb % (unsigned int)ft_strlen(base_to),
				index, base_to);
	}
	else
		(*c)[index] = base_to[nb];
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		div;
	char	*convert;
	int		nb;
	int		nbr_len;

	nbr_len = 0;
	nb = ft_atoi_base(nbr, base_from);
	div = nb;
	while (div / ft_strlen(base_to) != 0)
	{
		div = div / ft_strlen(base_to);
		nbr_len++;
	}
	nbr_len += (nb < 0) ? 2 : 1;
	if (!(convert = (char *)malloc(sizeof(char) * nbr_len)))
		return (0);
	convert[nbr_len] = 0;
	if (nb < 0)
	{
		convert[0] = '-';
		convert_to_base_to(&convert, nb * -1, nbr_len - 1, base_to);
	}
	else
		convert_to_base_to(&convert, nb, nbr_len - 1, base_to);
	return (convert);
}
