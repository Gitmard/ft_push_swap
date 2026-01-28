/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:43:14 by smenard           #+#    #+#             */
/*   Updated: 2026/01/28 11:29:32 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_bonus.h"

static void	rotate(t_stack *stack)
{
	ft_stackadd_tail(stack, ft_stackremove_head(stack));
}

void	ra(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.ra++;
	rotate(stacks->a);
}

void	rb(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.rb++;
	rotate(stacks->b);
}

void	rr(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.rr++;
	rotate(stacks->a);
	rotate(stacks->b);
}
