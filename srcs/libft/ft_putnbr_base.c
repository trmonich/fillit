/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:05:21 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/13 21:30:14 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_base(char *base)
{
	int i;

	if (*base == '\0' || *(base + 1) == '\0')
		return (0);
	while (*base != '\0')
	{
		if (*base == '+' || *base == '-')
			return (0);
		i = 1;
		while (*(base + i) != '\0')
		{
			if (*base == *(base + i))
				return (0);
			i++;
		}
		base++;
	}
	return (1);
}

void			ft_putnbr_base(int nb, char *base)
{
	int nb_base;

	nb_base = ft_strlen(base);
	if (!ft_check_base(base))
		return ;
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putnbr_base(-(nb / nb_base), base);
			ft_putchar(base[-(nb % nb_base)]);
		}
		else
			nb = -nb;
	}
	if (nb >= nb_base)
	{
		ft_putnbr_base(nb / nb_base, base);
		ft_putchar(base[nb % nb_base]);
	}
	else if (nb >= 0)
		ft_putchar(base[nb % nb_base]);
}
