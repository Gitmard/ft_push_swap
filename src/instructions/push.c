/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:32:31 by smenard           #+#    #+#             */
/*   Updated: 2026/01/07 16:35:36 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

static void	push(t_stack *from, t_stack *to)
{
	if (from->size == 0)
	{
		ft_printf("WARNING: tried to push from a stack of size 0\n");
		return ;
	}
	ft_stackadd_head(to, ft_stackremove_head(from));
}

void	pa(t_stacks *stacks)
{
	if (!(stacks->flags & NO_PRINT))
		ft_printf("pa\n");
	push(stacks->b, stacks->a);
}

void	pb(t_stacks *stacks)
{
	if (!(stacks->flags & NO_PRINT))
		ft_printf("pb\n");
	push(stacks->a, stacks->b);
}
