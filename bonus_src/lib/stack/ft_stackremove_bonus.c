/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackremove_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:05:32 by smenard           #+#    #+#             */
/*   Updated: 2026/01/28 11:37:47 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_bonus.h"

t_list	*ft_stackremove_head(t_stack *stack)
{
	t_list	*old_head;

	old_head = stack->head;
	stack->head = ft_lstremove_head(stack->head);
	if (stack->size == 1)
		stack->tail = NULL;
	stack->size -= 1;
	return (old_head);
}

t_list	*ft_stackremove_tail(t_stack *stack)
{
	t_list	*old_tail;

	old_tail = stack->tail;
	stack->tail = ft_lstremove_tail(stack->tail);
	if (stack->size == 1)
		stack->head = NULL;
	stack->size -= 1;
	return (old_tail);
}
