/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackremove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:05:32 by smenard           #+#    #+#             */
/*   Updated: 2026/01/06 17:45:34 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_list	*ft_stackremove_head(t_stack *stack)
{
	t_list	*old_head;

	old_head = stack->head;
	stack->head = ft_lstremove_head(stack->head);
	stack->size -= 1;
	return (old_head);
}

t_list	*ft_stackremove_tail(t_stack *stack)
{
	t_list	*old_tail;

	old_tail = stack->tail;
	stack->tail = ft_lstremove_tail(stack->tail);
	stack->size -= 1;
	return (old_tail);
}
