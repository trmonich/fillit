/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmonich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:29:53 by trmonich          #+#    #+#             */
/*   Updated: 2018/12/07 11:50:25 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*list;

	if (*alst == NULL)
	{
		ft_lstadd(alst, new);
		return ;
	}
	list = *alst;
	while (list->next)
		list = list->next;
	list->next = new;
}
