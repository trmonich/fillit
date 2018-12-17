/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:37:45 by trmonich          #+#    #+#             */
/*   Updated: 2018/12/14 12:23:47 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*new_str;

	new_str = (char*)malloc(sizeof(char) * (size + 1));
	if (!new_str)
		return (NULL);
	ft_bzero(new_str, size + 1);
	return (new_str);
}
