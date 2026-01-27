/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_defines.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:08:13 by smenard           #+#    #+#             */
/*   Updated: 2026/01/27 11:22:28 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_DEFINES_H
# define SIMPLE_DEFINES_H

# include "lib.h"

typedef struct s_costs
{
	int	a;
	int	b;
	int	combined;
}	t_costs;

typedef struct s_simple_metrics
{
	int		min;
	int		max;
	t_costs	cheapest_costs;
	t_list	*cheapest;
}			t_simple_metrics;

typedef enum e_exec_instruction_flags
{
	INCR = 1,
	DECR = 2,
	A = 4,
	B = 8
}	t_exec_instruction_flags;

typedef enum e_update_metrics_flags
{
	UPDATE_MAX = 1,
	UPDATE_COST = 2
}	t_update_metrics_flags;

#endif