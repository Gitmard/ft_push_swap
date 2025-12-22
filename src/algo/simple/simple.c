/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:32:42 by smenard           #+#    #+#             */
/*   Updated: 2026/01/27 11:24:45 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo_includes.h"
#include "simple_defines.h"
#include "simple_lib.h"

static void	exec_instruction(void (*instruction)(t_stacks *stacks), int flags,
		t_stacks *stacks, t_simple_metrics *metrics)
{
	int	sign;

	instruction(stacks);
	if (flags & INCR)
		sign = 1;
	else
		sign = -1;
	if (flags & A)
		metrics->cheapest_costs.a += sign;
	if (flags & B)
		metrics->cheapest_costs.b += sign;
}

static void	reorder_stack(t_stacks *stacks, t_simple_metrics metrics)
{
	ssize_t	min_index;
	t_list	*current;
	bool	use_rr;

	min_index = 0;
	current = stacks->a->head;
	while (current && current->value != metrics.min)
	{
		min_index++;
		current = current->next;
	}
	use_rr = min_index > (ssize_t)stacks->a->size / 2;
	while (min_index > 0 && min_index < (ssize_t)stacks->combined_sizes)
	{
		if (use_rr)
		{
			ra(stacks);
			min_index--;
		}
		else
		{
			rra(stacks);
			min_index++;
		}
	}
}

static void	combine_rotates(t_stacks *stacks, t_simple_metrics *metrics)
{
	if (ft_abs(metrics->cheapest_costs.a)
		> ft_abs(metrics->cheapest_costs.b))
	{
		while (metrics->cheapest_costs.b != 0)
		{
			if (metrics->cheapest_costs.a > 0)
				exec_instruction(rr, A | B | DECR, stacks, metrics);
			else
				exec_instruction(rrr, A | B | INCR, stacks, metrics);
		}
	}
	else
	{
		while (metrics->cheapest_costs.a != 0)
		{
			if (metrics->cheapest_costs.b > 0)
				exec_instruction(rr, A | B | DECR, stacks, metrics);
			else
				exec_instruction(rrr, A | B | INCR, stacks, metrics);
		}
	}
}

static void	push_cheapest(t_stacks *stacks, t_simple_metrics *metrics)
{
	if (metrics->cheapest_costs.a * metrics->cheapest_costs.b >= 0)
		combine_rotates(stacks, metrics);
	while (metrics->cheapest_costs.a != 0)
	{
		if (metrics->cheapest_costs.a > 0)
			exec_instruction(ra, A | DECR, stacks, metrics);
		else
			exec_instruction(rra, A | INCR, stacks, metrics);
	}
	while (metrics->cheapest_costs.b != 0)
	{
		if (metrics->cheapest_costs.b > 0)
			exec_instruction(rb, B | DECR, stacks, metrics);
		else
			exec_instruction(rrb, B | INCR, stacks, metrics);
	}
	pa(stacks);
	update_metrics(metrics, metrics->cheapest_costs, stacks->a->head,
		UPDATE_MAX);
}

void	simple(t_stacks *stacks)
{
	t_simple_metrics	metrics;
	t_list				*current;
	t_costs				current_costs;
	size_t				i;

	while (stacks->a->size)
		pb(stacks);
	init_metrics(&metrics, true);
	while (stacks->b->size)
	{
		i = 0;
		current = stacks->b->head;
		while (current)
		{
			current_costs = get_current_costs(stacks, current, i, metrics);
			update_metrics(&metrics, current_costs, current, UPDATE_COST);
			current = current->next;
			i++;
		}
		push_cheapest(stacks, &metrics);
		init_metrics(&metrics, false);
	}
	reorder_stack(stacks, metrics);
}
