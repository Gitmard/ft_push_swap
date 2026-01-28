/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:24:37 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/28 11:40:26 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_includes_bonus.h"

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
