/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:27:37 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/07 12:34:36 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isprint(int c)
{
	if (c >= 32 && c <= 39)
		return (1);
	if (c >= 40 && c <= 47)
		return (1);
	if (c >= 48 && c <= 63)
		return (1);
	if (c >= 64 && c <= 95)
		return (1);
	if (c >= 96 && c <= 126)
		return (1);
	return (0);
}