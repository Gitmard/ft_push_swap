/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:55:53 by vquetier          #+#    #+#             */
/*   Updated: 2026/02/07 14:02:57 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	raise_error(void)
{
	ft_putstr_stderr("Error\n");
	return (ERROR);
}

static float	calculate_disorder(t_stack *a)
{
	float	disorder;
	t_list	*current;

	if (a->size <= 1)
		return (0.0);
	current = a->head;
	disorder = 0;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			disorder++;
		current = current->next;
	}
	return (disorder / (float)(a->size - 1));
}

static int	handle_stacks(t_stacks *stacks)
{
	int		res;
	float	disorder;

	disorder = calculate_disorder(stacks->a);
	res = 0;
	if (stacks->flags & SIMPLE)
		simple(stacks);
	else if (stacks->flags & MEDIUM)
		res = medium(stacks);
	else if (stacks->flags & COMPLEX)
		complex(stacks);
	else
		res = adaptive(stacks, disorder);
	if (res == -1)
	{
		free_stacks(stacks, FREE_STACKS_ALL);
		return (raise_error());
	}
	if (stacks->flags & BENCH)
		bench(stacks, disorder);
	free_stacks(stacks, FREE_STACKS_ALL);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	stacks = parse(ac, av);
	if (!stacks)
		return (raise_error());
	if (is_sorted(stacks))
	{
		if (stacks->flags & BENCH)
			bench(stacks, calculate_disorder(stacks->a));
		free_stacks(stacks, FREE_STACKS_ALL);
		return (SUCCESS);
	}
	return (handle_stacks(stacks));
}
