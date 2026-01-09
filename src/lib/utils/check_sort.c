/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:24:37 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/12 13:39:10 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils_includes.h"

bool	is_sorted(t_stacks *stacks)
{
	t_list	*iter;

	if (stacks->b->head)
		return (false);
	if (stacks->combined_sizes <= 1)
		return (true);
	iter = stacks->a->head;
	while (iter->next)
	{
		if (iter->value > iter->next->value)
			return (false);
		iter = iter->next;
	}
	return (true);
}
