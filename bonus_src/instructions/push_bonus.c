/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:32:31 by smenard           #+#    #+#             */
/*   Updated: 2026/02/02 11:24:17 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_bonus.h"

static void	push(t_stack *from, t_stack *to)
{
	ft_stackadd_head(to, ft_stackremove_head(from));
}

void	pa(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.pa++;
	push(stacks->b, stacks->a);
}

void	pb(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.pb++;
	push(stacks->a, stacks->b);
}
