/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:43:14 by smenard           #+#    #+#             */
/*   Updated: 2026/01/09 16:49:22 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

static void	rotate(t_stack *stack)
{
	if (stack->size == 0)
	{
		ft_printf("WARNING: tried to rotate a stack of size 0\n");
		return ;
	}
	ft_stackadd_tail(stack, ft_stackremove_head(stack));
}

void	ra(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.ra++;
	if (!(stacks->flags & NO_PRINT))
		ft_printf("ra\n");
	rotate(stacks->a);
}

void	rb(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.rb++;
	if (!(stacks->flags & NO_PRINT))
		ft_printf("rb\n");
	rotate(stacks->b);
}

void	rr(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.rr++;
	if (!(stacks->flags & NO_PRINT))
		ft_printf("rr\n");
	rotate(stacks->a);
	rotate(stacks->b);
}
