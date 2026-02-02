/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:32:31 by smenard           #+#    #+#             */
/*   Updated: 2026/02/02 16:16:52 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_bonus.h"

static void	push(t_stack *from, t_stack *to)
{
	if (from->size <= 0)
		return ;
	ft_stackadd_head(to, ft_stackremove_head(from));
}

void	pa(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.pa++;
	push(stacks->b, stacks->a);
}

void	pb(t_stacks *stacks)
{
	stacks->op.total++;
	stacks->op.pb++;
	push(stacks->a, stacks->b);
}
