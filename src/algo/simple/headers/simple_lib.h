/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:01:33 by smenard           #+#    #+#             */
/*   Updated: 2026/01/27 11:24:27 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_LIB_H
# define SIMPLE_LIB_H

# include "algo_includes.h"
# include "simple_defines.h"

int		get_a_cost(t_stack *a, t_list *node, int min, int max);

int		get_b_cost(t_stack *b, size_t current_index);

t_costs	get_current_costs(t_stacks *stacks, t_list *node, size_t current_index,
			t_simple_metrics metrics);

void	init_metrics(t_simple_metrics *metrics, bool reset_min_max);

void	update_metrics(t_simple_metrics *metrics,
			t_costs current_costs,
			t_list *current_node,
			int flags);

#endif