/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:26:58 by smenard           #+#    #+#             */
/*   Updated: 2026/01/08 17:23:55 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "list_lib.h"

t_list	*ft_lstremove_head(t_list *lst)
{
	t_list	*new_head;
	t_list	*previous_head;

	if (!lst)
		return (NULL);
	previous_head = lst;
	while (previous_head->prev)
		previous_head = previous_head->prev;
	new_head = previous_head->next;
	if (new_head)
		new_head->prev = NULL;
	reset_link(previous_head);
	return (new_head);
}

t_list	*ft_lstremove_tail(t_list *lst)
{
	t_list	*new_tail;
	t_list	*previous_tail;

	if (!lst)
		return (NULL);
	previous_tail = lst;
	while (previous_tail->next)
		previous_tail = previous_tail->next;
	new_tail = previous_tail->prev;
	if (new_tail)
		new_tail->next = NULL;
	reset_link(previous_tail);
	return (new_tail);
}
