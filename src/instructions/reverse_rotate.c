/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:47:09 by smenard           #+#    #+#             */
/*   Updated: 2026/02/02 11:22:40 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "instructions.h"

static void	reverse_rotate(t_stack *stack)
{
	if (stack->size == 0)
		return ;
	ft_stackadd_head(stack, ft_stackremove_tail(stack));
}

void	rra(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.rra++;
	ft_printf("rra\n");
	reverse_rotate(stacks->a);
}

void	rrb(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.rrb++;
	ft_printf("rrb\n");
	reverse_rotate(stacks->b);
}

void	rrr(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.rrr++;
	ft_printf("rrr\n");
	reverse_rotate(stacks->a);
	reverse_rotate(stacks->b);
}
