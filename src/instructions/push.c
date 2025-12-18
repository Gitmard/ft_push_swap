/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:32:31 by smenard           #+#    #+#             */
/*   Updated: 2025/12/18 19:58:01 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

static void	push(t_stack *from, t_stack *to)
{
	if (from->size == 0)
		return ;
	ft_stackadd_head(to, ft_stackremove_head(from));
}

void	push_a(t_stacks *stacks)
{
	push(stacks->stack_b, stacks->stack_a);
}

void	push_b(t_stacks *stacks)
{
	push(stacks->stack_a, stacks->stack_b);
}
