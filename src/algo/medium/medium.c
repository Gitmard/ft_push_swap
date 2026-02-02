/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:51:45 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/28 11:36:32 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "medium_defines.h"

void	(*locate_closest(t_stacks *stacks, uint32_t w_start,
		uint32_t w_size))(t_stacks *stacks)
{
	t_list	*forward;
	t_list	*backward;

	forward = stacks->a->head->next;
	backward = stacks->a->tail;
	while (forward && backward)
	{
		if (forward->target_index >= w_start
			&& forward->target_index <= w_start + w_size)
			return (&ra);
		if (backward->target_index >= w_start
			&& backward->target_index <= w_start + w_size)
			return (&rra);
		forward = forward->next;
		backward = backward->prev;
	}
	return (&ra);
}

int	fill_buckets(t_stacks *stacks, uint32_t w_size)
{
	uint32_t	w_start;
	bool		*poped;
	void		(*f)(t_stacks *);

	w_start = 0;
	poped = ft_calloc(stacks->combined_sizes, sizeof(bool));
	if (!poped)
		return (ERROR);
	while (stacks->a->size > 0)
	{
		ensure_w_size_is_correct(&w_size, w_start, stacks->combined_sizes);
		f = locate_closest(stacks, w_start, w_size);
		while (!(stacks->a->head->target_index >= w_start
				&& stacks->a->head->target_index <= w_start + w_size))
			f(stacks);
		poped[stacks->a->head->target_index] = true;
		update_stacks(w_start, w_size, stacks);
		update_window(&w_start, w_size, poped, stacks->combined_sizes);
	}
	free(poped);
	return (SUCCESS);
}

void	(*locate_top(t_stacks *stacks, uint32_t target))(t_stacks *stacks)
{
	t_list	*forward;
	t_list	*backward;

	if (stacks->b->head->target_index == target)
		return (&ra);
	forward = stacks->b->head->next;
	backward = stacks->b->tail;
	while (forward && backward)
	{
		if (forward->target_index == target)
			return (&rb);
		else if (backward->target_index == target)
			return (&rrb);
		forward = forward->next;
		backward = backward->prev;
	}
	return (&ra);
}

void	insert_in_a(t_stacks *stacks, uint32_t size)
{
	uint32_t	top_index;
	void		(*f)(t_stacks *);

	top_index = size;
	while (top_index > 0)
	{
		top_index--;
		f = locate_top(stacks, top_index);
		while (stacks->b->head->target_index != top_index)
			f(stacks);
		pa(stacks);
	}
}

int	medium(t_stacks *stacks)
{
	uint32_t	w_size;

	w_size = ft_sqrt(stacks->a->size);
	if (fill_buckets(stacks, w_size))
		return (ERROR);
	insert_in_a(stacks, stacks->b->size);
	return (SUCCESS);
}
