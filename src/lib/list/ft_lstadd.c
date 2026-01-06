/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:27:15 by smenard           #+#    #+#             */
/*   Updated: 2026/01/06 17:50:16 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static t_list	*reset_link(t_list *link)
{
	if (!link)
		return (NULL);
	link->prev = NULL;
	link->next = NULL;
	return (link);
}

t_list	*ft_lstadd_new_head(t_list *lst, int value)
{
	t_list	*new;

	new = ft_lstnew(value);
	return (ft_lstadd_head(lst, new));
}

t_list	*ft_lstadd_head(t_list *lst, t_list *new)
{
	if (!lst)
		return (reset_link(new));
	if (!new)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	lst->prev = new;
	new->next = lst;
	new->prev = NULL;
	return (new);
}

t_list	*ft_lstadd_new_tail(t_list *lst, int value)
{
	t_list	*new;

	new = ft_lstnew(value);
	return (ft_lstadd_tail(lst, new));
}

t_list	*ft_lstadd_tail(t_list *lst, t_list *new)
{
	if (!lst)
		return (new);
	if (!new)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	lst->next = new;
	new->prev = lst;
	new->next = NULL;
	return (new);
}
