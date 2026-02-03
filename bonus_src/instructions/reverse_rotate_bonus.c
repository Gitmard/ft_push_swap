/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:47:09 by smenard           #+#    #+#             */
/*   Updated: 2026/02/02 16:53:10 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_bonus.h"

static void	reverse_rotate(t_stack *stack)
{
	ft_stackadd_head(stack, ft_stackremove_tail(stack));
}

void	rra(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.rra++;
	reverse_rotate(stacks->a);
}

void	rrb(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.rrb++;
	reverse_rotate(stacks->b);
}

void	rrr(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.rrr++;
	reverse_rotate(stacks->a);
	reverse_rotate(stacks->b);
}
