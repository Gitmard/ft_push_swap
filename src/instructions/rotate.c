/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:43:14 by smenard           #+#    #+#             */
/*   Updated: 2025/12/22 19:39:51 by smenard          ###   ########.fr       */
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
	rotate(stacks->stack_a);
}

void	rb(t_stacks *stacks)
{
	rotate(stacks->stack_b);
}

void	rr(t_stacks *stacks)
{
	rotate(stacks->stack_a);
	rotate(stacks->stack_b);
}
