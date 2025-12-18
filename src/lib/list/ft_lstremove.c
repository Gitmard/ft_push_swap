/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:26:58 by smenard           #+#    #+#             */
/*   Updated: 2025/12/18 17:40:13 by smenard          ###   ########.fr       */
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
	new_tail->next = NULL;
	return (new_tail);
}
