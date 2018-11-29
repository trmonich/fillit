/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:00:23 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/14 08:56:34 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int				i;
	unsigned long	nb;
	int				sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-') ? -1 : 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nb > nb * 10 + (str[i] - '0'))
			return ((sign == -1) ? 0 : -1);
		nb = nb * 10 + (str[i++] - '0');
	}
	return (nb * sign);
}
