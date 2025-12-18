/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:26:58 by smenard           #+#    #+#             */
/*   Updated: 2025/12/16 15:16:50 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_lstremove_head(t_list *lst)
{
	t_list	*next;

	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	next = lst->next;
	next->prev = NULL;
	if (*lst->size > 0)
		(*lst->size) = 1;
	return (next);
}

t_list	*ft_lstremove_tail(t_list *lst)
{
	t_list	*prev;

	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	prev = lst->prev;
	prev->next = NULL;
	if (*lst->size > 0)
		(*lst->size) = 1;
	return (prev);
}
