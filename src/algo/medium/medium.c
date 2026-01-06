/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:51:45 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/06 16:06:13 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "medium_defines.h"

void	(*locate_closest(t_stacks *stacks, int w_start, int w_size, int *sorted))(t_stacks *stacks)
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
		(*w_start)++;
}

int	fill_buckets(t_stacks *stacks, int *sorted, int w_size, int *steps)
{
	int		w_start;
	int		size;
	bool	*poped;
	void	(*f)(t_stacks *);

	size = stacks->stack_a->size;
	poped = ft_calloc(size, sizeof(bool));
	if (!poped)
		return (1);
	while (stacks->stack_a->size > 0)
	{
		f = locate_closest(stacks, w_start, w_size, sorted);
		while (!(stacks->stack_a->head->value >= sorted[w_start]
				&& stacks->stack_a->head->value <= sorted[w_start + w_size]))
		{
			f(stacks);
			(*steps)++;
		}
		update_poped(w_start, stacks->stack_a->head->value, poped, sorted);
		pb(stacks);
		if (stacks->stack_b->head->value <= sorted[w_start + w_size / 2])
			rb(stacks);
		update_window(&w_start, w_size, poped, size);
		(*steps)++;
	}
	return (0);
}

void	(*locate_top(t_stacks *stacks, int target))(t_stacks *stacks)
{
	t_list	*forward;
	t_list	*backward;

	if (stacks->stack_b->head->value == target)
		return (&ra);
	forward = stacks->stack_b->head->next;
	backward = stacks->stack_b->tail;
	while (forward && backward)
	{
		if (forward->value == target)
			return (&rb);
		else if (backward->value == target)
			return (&rrb);
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
	w_size = ft_sqrt(stacks->stack_a->size);
	steps = 0;
	if (fill_buckets(stacks, sorted, w_size, &steps))
	{
		free(sorted);
		return (-1);
	}
	insert_in_a(stacks, sorted, stacks->stack_b->size, &steps);
	return (steps);
}
