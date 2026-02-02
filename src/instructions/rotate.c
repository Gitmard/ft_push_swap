/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:43:14 by smenard           #+#    #+#             */
/*   Updated: 2026/02/02 11:22:31 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

static void	rotate(t_stack *stack)
{
	if (stack->size == 0)
		return ;
	ft_stackadd_tail(stack, ft_stackremove_head(stack));
}

void	ra(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.ra++;
	ft_printf("ra\n");
	rotate(stacks->a);
}

void	rb(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.rb++;
	ft_printf("rb\n");
	rotate(stacks->b);
}

void	rr(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.rr++;
	ft_printf("rr\n");
	rotate(stacks->a);
	rotate(stacks->b);
}
