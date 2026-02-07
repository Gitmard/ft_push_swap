/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_metrics_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:00:48 by smenard           #+#    #+#             */
/*   Updated: 2026/02/07 14:06:02 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo_includes.h"
#include "simple_defines.h"

int	get_a_cost(t_stack *a, t_list *node, int min, int max)
{
	t_list	*current;
	t_list	*previous_node;
	int		target_index;

	current = a->head;
	target_index = 0;
	if (min > node->value)
		min = node->value;
	if (max < node->value)
		max = node->value;
	while (current && current->next)
	{
		previous_node = get_previous_node(current, a->tail);
		if (!previous_node)
			return (-1);
		if ((previous_node->value < node->value || (previous_node->value == max
					&& current->value != min)) && (current->value > node->value
				|| (current->value == min && previous_node->value != max)))
			break ;
		target_index++;
		current = current->next;
	}
	if (((int)a->size - target_index) < target_index)
		return (target_index - a->size);
	return (target_index);
}

int	get_b_cost(t_stack *b, size_t current_index)
{
	if (b->size - current_index < current_index)
		return (current_index - b->size);
	return (current_index);
}

t_costs	get_current_costs(t_stacks *stacks, t_list *node, size_t current_index,
		t_simple_metrics metrics)
{
	t_costs	costs;

	costs.a = get_a_cost(stacks->a, node, metrics.min, metrics.max);
	costs.b = get_b_cost(stacks->b, current_index);
	if (costs.a * costs.b > 0)
		costs.combined = ft_max(ft_abs(costs.a), ft_abs(costs.b));
	else
		costs.combined = ft_abs(costs.a) + ft_abs(costs.b);
	return (costs);
}

void	init_metrics(t_simple_metrics *metrics, bool reset_min_max)
{
	metrics->cheapest = NULL;
	metrics->cheapest_costs.a = INT32_MAX;
	metrics->cheapest_costs.b = INT32_MAX;
	metrics->cheapest_costs.combined = INT32_MAX;
	if (reset_min_max)
	{
		metrics->max = INT32_MIN;
		metrics->min = INT32_MAX;
	}
}

void	update_metrics(t_simple_metrics *metrics, t_costs current_costs,
		t_list *current_node, int flags)
{
	if (flags & UPDATE_COST
		&& current_costs.combined < metrics->cheapest_costs.combined)
	{
		metrics->cheapest_costs = current_costs;
		metrics->cheapest = current_node;
	}
	if (flags & UPDATE_MAX && current_node->value > metrics->max)
		metrics->max = current_node->value;
	if (flags & UPDATE_MAX && current_node->value < metrics->min)
		metrics->min = current_node->value;
}
