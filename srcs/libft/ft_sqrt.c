/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 18:17:22 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/13 21:28:30 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		ft_create_res(int nb, int *res)
{
	int a;

	if (*res < 46340)
	{
		a = *res * *res;
		if (a < nb)
		{
			*res = *res + 1;
			ft_create_res(nb, res);
		}
		else if (a > nb)
		{
			*res = 0;
		}
	}
	else if (nb != *res * *res)
		*res = 0;
}

int				ft_sqrt(int nb)
{
	int res;

	res = 1;
	if (nb < 1)
		return (0);
	else
		ft_create_res(nb, &res);
	return (res);
}
