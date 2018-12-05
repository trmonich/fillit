/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:04:26 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/13 16:51:24 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	new = NULL;
	if (lst && f)
	{
		if (!(new = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		new = (*f)(lst);
		new->next = ft_lstmap(lst->next, f);
	}
	return (new);
}
