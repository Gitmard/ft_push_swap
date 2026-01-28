/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:15:25 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/27 11:49:13 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "medium_defines.h"

void	update_poped(int w_start, int value, bool *poped, int *sorted)
{
	int	i;

	i = w_start;
	while (sorted[i] != value)
		i++;
	poped[i] = true;
}

void	update_window(int *w_start, int w_size, bool *poped, size_t size)
{
	while ((size_t)((*w_start) + w_size + 1) < size && poped[(*w_start)])
		(*w_start)++;
}

void	update_stacks(int w_start, int w_size, int *sorted, t_stacks *stacks)
{
	pb(stacks);
	if (stacks->b->head->value <= sorted[w_start + w_size / 2]
		&& stacks->b->size > 1)
		rb(stacks);
}

void	ensure_w_size_is_correct(int *w_size, int w_start, uint32_t full_size)
{
	if (w_start + *w_size >= (int)full_size)
		*w_size = (int)full_size - w_start - 1;
}
