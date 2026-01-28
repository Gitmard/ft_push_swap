/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:15:25 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/28 12:54:47 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "medium_defines.h"

void	update_window(uint32_t *w_start, uint32_t w_size,
		bool *poped, size_t size)
{
	while ((size_t)((*w_start) + w_size + 1) < size && poped[(*w_start)])
		(*w_start)++;
}

void	update_stacks(uint32_t w_start, uint32_t w_size, t_stacks *stacks)
{
	pb(stacks);
	if (stacks->b->head->target_index <= w_start + w_size / 2
		&& stacks->b->size > 1)
		rb(stacks);
}

void	ensure_w_size_is_correct(uint32_t *w_size, uint32_t w_start,
		uint32_t full_size)
{
	if (w_start + *w_size >= full_size)
		*w_size = full_size - w_start - 1;
}
