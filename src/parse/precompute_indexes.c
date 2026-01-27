/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_indexes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:25:15 by smenard           #+#    #+#             */
/*   Updated: 2026/01/27 13:47:53 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_defines.h"

static int	precompute_free_return(int *sorted, int value)
{
	free(sorted);
	return (value);
}

int	precompute_indexes(t_stacks *stacks)
{
	int		*sorted;
	size_t	i;
	t_list	*current;
	int		current_index;

	sorted = create_sorted_array(stacks);
	if (!sorted)
		return (ERROR);
	i = 0;
	current = stacks->a->head;
	while (current)
	{
		current_index = binary_search(current->value, sorted,
				stacks->combined_sizes);
		if (current_index < 0)
			return (precompute_free_return(sorted, ERROR));
		current->target_index = current_index;
		current = current->next;
	}
	return (precompute_free_return(sorted, SUCCESS));
}
