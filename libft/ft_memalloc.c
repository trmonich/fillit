/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:58:26 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/08 15:09:05 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*new_zone;

	new_zone = malloc(sizeof(*new_zone) * size);
	if (!new_zone)
		return (NULL);
	return (ft_bzero(new_zone, size));
}
