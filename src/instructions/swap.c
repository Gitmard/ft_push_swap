/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:15:23 by smenard           #+#    #+#             */
/*   Updated: 2025/12/22 19:39:32 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

static bool	swap(t_stack *stack)
{
	t_list	*swap_temp1;
	t_list	*swap_temp2;

	if (stack->size < 2)
	{
		ft_printf("WARNING: tried to swap a stack of size %d\n", stack->size);
		return (false);
	}
	swap_temp1 = ft_stackremove_head(stack);
	swap_temp2 = ft_stackremove_head(stack);
	ft_stackadd_head(stack, swap_temp1);
	ft_stackadd_head(stack, swap_temp2);
	return (true);
}

void	sa(t_stacks *stacks)
{
	swap(stacks->stack_a);
}

void	sb(t_stacks *stacks)
{
	swap(stacks->stack_b);
}

void	ss(t_stacks *stacks)
{
	swap(stacks->stack_a);
	swap(stacks->stack_b);
}
