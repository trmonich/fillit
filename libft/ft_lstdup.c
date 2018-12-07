/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:20:56 by alesteph          #+#    #+#             */
/*   Updated: 2018/12/07 12:36:27 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *src)
{
	t_list	*dst;

	dst = NULL;
	while (src)
	{
		ft_lstappend(&dst, ft_lstnew(src->content, src->content_size));
		src = src->next;
	}
	return (dst);
}
