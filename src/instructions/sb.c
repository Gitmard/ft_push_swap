/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:43:56 by vquetier          #+#    #+#             */
/*   Updated: 2025/12/17 15:45:06 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_defines.h"

void	sb(t_stacks *stacks)
{
	t_list	*new;
	t_list	*node;

	if (stacks->stack_b->size < 2)
		return ;
	new = stacks->stack_b->head;
	node = new->next;
	new->prev = node;
	new->next = node->next;
	node->prev = NULL;
	node->next = new;
	new = node;
	stacks->stack_b->head = new;
	if (stacks->stack_b->size == 2)
		stacks->stack_b->tail = node;
}
