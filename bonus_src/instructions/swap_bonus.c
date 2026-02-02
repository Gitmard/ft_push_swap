/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:15:23 by smenard           #+#    #+#             */
/*   Updated: 2026/02/02 17:22:12 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_bonus.h"

static bool	swap(t_stack *stack)
{
	t_list	*swap_temp1;
	t_list	*swap_temp2;

	if (stack->size <= 1)
		return (false);
	swap_temp1 = ft_stackremove_head(stack);
	swap_temp2 = ft_stackremove_head(stack);
	ft_stackadd_head(stack, swap_temp1);
	ft_stackadd_head(stack, swap_temp2);
	return (true);
}

void	sa(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.sa++;
	swap(stacks->a);
}

void	sb(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.sb++;
	swap(stacks->b);
}

void	ss(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.ss++;
	swap(stacks->a);
	swap(stacks->b);
}
