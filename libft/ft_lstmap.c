/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:51:06 by trmonich          #+#    #+#             */
/*   Updated: 2018/11/29 11:51:27 by trmonich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*buff;
	t_list	*previous;

	if (!lst)
		return (NULL);
	if (!(new = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (NULL);
	buff = new;
	previous = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			return (NULL);
		previous->next = new;
		previous = new;
		lst = lst->next;
	}
	return (buff);
}
