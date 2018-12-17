/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:16:01 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/12 12:32:30 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new_str;

	if (!s)
		return (NULL);
	i = 0;
	new_str = (char*)malloc(ft_strlen(s) + 1);
	if (!new_str)
		return (NULL);
	while (s[i])
	{
		new_str[i] = f(s[i]);
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}
