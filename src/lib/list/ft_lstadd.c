/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:27:15 by smenard           #+#    #+#             */
/*   Updated: 2026/02/03 14:14:40 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "list_lib.h"

t_list	*ft_lstadd_head(t_list *lst, t_list *new)
{
	t_list	*previous_head;

	if (!lst)
		return (reset_link(new));
	if (!new)
		return (NULL);
	previous_head = lst;
	while (previous_head->prev)
		previous_head = previous_head->prev;
	previous_head->prev = new;
	new->next = previous_head;
	new->prev = NULL;
	return (new);
}

t_list	*ft_lstadd_tail(t_list *lst, t_list *new)
{
	t_list	*previous_tail;

	if (!lst)
		return (reset_link(new));
	if (!new)
		return (NULL);
	previous_tail = lst;
	while (previous_tail->next)
		previous_tail = previous_tail->next;
	previous_tail->next = new;
	new->prev = previous_tail;
	new->next = NULL;
	return (new);
}
