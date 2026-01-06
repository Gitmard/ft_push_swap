/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:04:29 by smenard           #+#    #+#             */
/*   Updated: 2026/01/06 17:48:12 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_list	*ft_stackadd_new_head(t_stack *stack, int value)
{
	stack->head = ft_lstadd_new_head(stack->head, value);
	if (!stack->tail)
		stack->tail = stack->head;
	stack->size += 1;
	return (stack->head);
}

t_list	*ft_stackadd_head(t_stack *stack, t_list *new_head)
{
	stack->head = ft_lstadd_head(stack->head, new_head);
	if (!stack->tail)
		stack->tail = stack->head;
	stack->size += 1;
	return (stack->head);
}

t_list	*ft_stackadd_new_tail(t_stack *stack, int value)
{
	stack->tail = ft_lstadd_new_tail(stack->tail, value);
	if (!stack->head)
		stack->head = stack->tail;
	stack->size += 1;
	return (stack->tail);
}

t_list	*ft_stackadd_tail(t_stack *stack, t_list *new_tail)
{
	stack->tail = ft_lstadd_tail(stack->tail, new_tail);
	if (!stack->head)
		stack->head = stack->tail;
	stack->size += 1;
	return (stack->tail);
}
