/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:47:09 by smenard           #+#    #+#             */
/*   Updated: 2025/12/22 19:40:03 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

static void	reverse_rotate(t_stack *stack)
{
	if (stack->size == 0)
	{
		ft_printf("WARNING: tried to reverse rotate a stack of size 0\n");
		return ;
	}
	ft_stackadd_head(stack, ft_stackremove_tail(stack));
}

void	rra(t_stacks *stacks)
{
	reverse_rotate(stacks->a);
}

void	rrb(t_stacks *stacks)
{
	reverse_rotate(stacks->b);
}

void	rrr(t_stacks *stacks)
{
	reverse_rotate(stacks->a);
	reverse_rotate(stacks->b);
}
