/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:51:45 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/07 16:13:23 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "medium_defines.h"

void	(*locate_closest(t_stacks *stacks, int w_start,
	int w_size, int *sorted))(t_stacks *stacks)
{
	t_list	*forward;
	t_list	*backward;

	forward = stacks->a->head->next;
	backward = stacks->a->tail;
	while (forward && backward)
	{
		if (forward->value >= sorted[w_start]
			&& forward->value <= sorted[w_start + w_size])
			return (&ra);
		if (backward->value >= sorted[w_start
				&& backward->value <= sorted[w_start + w_size]])
			return (&rra);
		forward = forward->next;
		backward = backward->prev;
	}
	return (&ra);
}

int	fill_buckets(t_stacks *stacks, int *sorted, int w_size, int *steps)
{
	int		w_start;
	bool	*poped;
	void	(*f)(t_stacks *);

	w_start = 0;
	poped = ft_calloc(stacks->combined_sizes, sizeof(bool));
	if (!poped)
		return (ERROR);
	while (stacks->a->size > 0)
	{
		f = locate_closest(stacks, w_start, w_size, sorted);
		while (!(stacks->a->head->value >= sorted[w_start]
				&& stacks->a->head->value <= sorted[w_start + w_size]))
		{
			f(stacks);
			(*steps)++;
		}
		update_poped(w_start, stacks->a->head->value, poped, sorted);
		update_stacks(w_start, w_size, sorted, stacks);
		update_window(&w_start, w_size, poped, stacks->combined_sizes);
		(*steps)++;
	}
	free(poped);
	return (SUCCESS);
}

void	(*locate_top(t_stacks *stacks, int target))(t_stacks *stacks)
{
	t_list	*forward;
	t_list	*backward;

	if (stacks->b->head->value == target)
		return (&ra);
	forward = stacks->b->head->next;
	backward = stacks->b->tail;
	while (forward && backward)
	{
		if (forward->value == target)
			return (&rb);
		else if (backward->value == target)
			return (&rrb);
		forward = forward->next;
		backward = backward->prev;
	}
	return (&ra);
}

void	insert_in_a(t_stacks *stacks, int *sorted, int size, int *steps)
{
	int		top_index;
	void	(*f)(t_stacks *);

	top_index = size - 1;
	while (top_index >= 0)
	{
		f = locate_top(stacks, sorted[top_index]);
		while (stacks->b->head->value != sorted[top_index])
		{
			(*steps)++;
			f(stacks);
		}
		pa(stacks);
		(*steps)++;
		top_index--;
	}
}

int	medium(t_stacks *stacks)
{
	int	*sorted;
	int	w_size;
	int	steps;

	sorted = create_sorted_array(stacks);
	if (!sorted)
		return (-1);
	w_size = ft_sqrt(stacks->a->size);
	steps = 0;
	if (fill_buckets(stacks, sorted, w_size, &steps))
	{
		free(sorted);
		return (-1);
	}
	insert_in_a(stacks, sorted, stacks->b->size, &steps);
	free(sorted);
	return (steps);
}
