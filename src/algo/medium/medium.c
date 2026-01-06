/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:51:45 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/06 13:48:48 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "medium_defines.h"

void	(*locate_closest(t_stacks *))(t_stacks *stacks,
		int w_start, int w_size, int *sorted)
{
	t_list	*forward;
	t_list	*backward;

	forward = stacks->stack_a->head->next;
	backward = stacks->stack_a->tail;
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

void	update_poped(int w_start, int value, bool *poped, int *sorted)
{
	int	i;

	i = w_start;
	while (sorted[i] != value)
		i++;
	poped[i] = true;
}

void	update_window(int *w_start, int w_size, bool *poped, int size)
{
	while ((*w_start) + w_size + 1 < size && poped[(*w_start)])
		(*w_start++);
}

int	fill_buckets(t_stacks *stacks, int *sorted, int w_size, int *steps)
{
	int		w_start;
	int		size;
	bool	*poped;
	void	(*f)(t_stacks *);

	poped = ft_calloc(stacks->stack_a->size, sizeof(bool));
	if (!poped)
		return (1);
	while (stacks->stack_a->size > 0)
	{
		f = locate_closest(stacks);
		while (!(stacks->stack_a->head->value >= sorted[w_start]
				&& stacks->stack_a->head->value <= sorted[w_start + w_size]))
		{
			f(stacks);
			(*steps)++;
		}
		update_poped(w_start, stacks->stack_a->head->value, poped, size);
		pb(stacks);
		if (stacks->stack_b->head->value <= sorted[w_start + w_size / 2])
			rb(stacks);
		update_window(*w_start, w_size, poped, size);
		(*steps)++;
	}
}

void	(*locate_top(t_stacks *))(t_stacks *stacks, int target)
{
	t_list	*forward;
	t_list	*backward;

	if (!stacks->stack_b->head->value == sorted[top_index])
		return (&ra);
	forward = stacks->stack_b->head->next;
	backward = stacks->stack_b->tail;
	while (forward && backward)
	{
		if (forward->value == sorted[top_index])
			return (&rb);
		else if (backward->value == sorted[top_index])
			return (&rrb);
	}
}

void	insert_in_a(t_stacks *stacks, int *sorted, int size, int *steps)
{
	int		top_index;
	void	(*f)(t_stacks *);

	top_index = size - 1;
	while (top_index >= 0)
	{
		f = loacate_top(stacks, sorted[top_index]);
		while (stacks->stack_a->head->value != sorted[top_index])
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
	w_size = sqrt(stacks->stack_a->size);
	steps = 0;
	if (fill_buckets(stacks, sorted, w_size, &steps))
	{
		free(sorted);
		return (-1);
	}
	insert_in_a(stacks, sorted, stacks->strack_b->size, &steps);
	return (steps);
}
