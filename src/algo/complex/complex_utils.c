/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:26:26 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/28 17:28:22 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "complex_defines.h"

int	get_max_push(t_stacks *stacks, int bit)
{
	int		max_push;
	t_list	*iter;

	max_push = 0;
	iter = stacks->a->head;
	while (iter)
	{
		if (!(iter->target_index & bit))
			max_push++;
		iter = iter->next;
	}
	return (max_push);
}

int	get_max_bits(t_stacks *stacks)
{
	int	max;
	int	max_bits;
	int	curr_bit;

	max = stacks->a->size - 1;
	max_bits = 0;
	curr_bit = 0;
	while (curr_bit < 32)
	{
		if (max & (1 << curr_bit))
			max_bits = curr_bit + 1;
		curr_bit++;
	}
	return (max_bits);
}
