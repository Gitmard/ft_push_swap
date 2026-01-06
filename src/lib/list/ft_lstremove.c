/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:26:58 by smenard           #+#    #+#             */
/*   Updated: 2026/01/06 17:58:37 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_lstremove_head(t_list *lst)
{
	t_list	*new_head;

	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	new_head = lst->next;
	if (new_head)
		new_head->prev = NULL;
	return (new_head);
}

t_list	*ft_lstremove_tail(t_list *lst)
{
	t_list	*new_tail;

	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	new_tail = lst->prev;
	if (new_tail)
		new_tail->next = NULL;
	return (new_tail);
}
