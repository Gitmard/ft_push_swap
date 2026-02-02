/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:15:23 by smenard           #+#    #+#             */
/*   Updated: 2026/02/02 11:23:23 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "instructions.h"

static bool	swap(t_stack *stack)
{
	t_list	*swap_temp1;
	t_list	*swap_temp2;

	if (stack->size < 2)
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
	ft_printf("sa\n");
	swap(stacks->a);
}

void	sb(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.sb++;
	ft_printf("sb\n");
	swap(stacks->b);
}

void	ss(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.ss++;
	ft_printf("ss\n");
	swap(stacks->a);
	swap(stacks->b);
}
