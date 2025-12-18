/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:47:09 by smenard           #+#    #+#             */
/*   Updated: 2025/12/18 19:53:19 by smenard          ###   ########.fr       */
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

void	reverse_rotate_a(t_stacks *stacks)
{
	reverse_rotate(stacks->stack_a);
}

void	reverse_rotate_b(t_stacks *stacks)
{
	reverse_rotate(stacks->stack_b);
}

void	reverse_rotate_all(t_stacks *stacks)
{
	reverse_rotate(stacks->stack_a);
	reverse_rotate(stacks->stack_b);
}
