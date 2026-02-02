/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:59:58 by vquetier          #+#    #+#             */
/*   Updated: 2026/02/02 17:29:26 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex_defines.h"

static void	rotate_a(t_stacks *stacks, int rotate_count)
{
	void	(*f)(t_stacks *stacks);

	if ((size_t)rotate_count == stacks->a->size)
		return ;
	f = rra;
	if ((size_t)rotate_count > stacks->a->size / 2)
	{
		rotate_count = stacks->a->size - rotate_count;
		f = ra;
	}
	while (rotate_count > 0)
	{
		f(stacks);
		rotate_count--;
	}
}

static void	push_in_b(t_stacks *stacks, int curr_bit)
{
	int	bit;
	int	max_push;
	int	push_count;
	int	rotate_count;

	bit = 1 << curr_bit;
	max_push = get_max_push(stacks, bit);
	push_count = 0;
	rotate_count = 0;
	while (push_count < max_push)
	{
		if (!(stacks->a->head->target_index & bit))
		{
			pb(stacks);
			push_count++;
		}
		else
		{
			ra(stacks);
			rotate_count++;
		}
	}
	rotate_a(stacks, rotate_count);
}

static void	push_in_a(t_stacks *stacks, int curr_bit, int max_bits)
{
	int	to_push;
	int	bit;

	to_push = stacks->b->size;
	bit = 1 << (curr_bit + 1);
	while (to_push > 0)
	{
		if (!(stacks->b->head->target_index & bit)
			&& curr_bit < max_bits - 1)
			rb(stacks);
		else
			pa(stacks);
		to_push--;
	}
}

void	complex(t_stacks *stacks)
{
	int	max_bits;
	int	curr_bit;

	max_bits = get_max_bits(stacks);
	curr_bit = 0;
	while (curr_bit < max_bits && !is_sorted(stacks))
	{
		push_in_b(stacks, curr_bit);
		push_in_a(stacks, curr_bit, max_bits);
		curr_bit++;
	}
}
