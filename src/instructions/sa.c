/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:21:52 by vquetier          #+#    #+#             */
/*   Updated: 2025/12/17 15:43:20 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_defines.h"

void	sa(t_stacks *stacks)
{
	t_list	*new;
	t_list	*node;

	if (stacks->stack_a->size < 2)
		return ;
	new = stacks->stack_a->head;
	node = new->next;
	new->prev = node;
	new->next = node->next;
	node->prev = NULL;
	node->next = new;
	new = node;
	stacks->stack_a->head = new;
	if (stacks->stack_a->size == 2)
		stacks->stack_a->tail = node;
}
