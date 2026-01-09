/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:55:53 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/09 17:14:38 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

/*
static void	print_stack(t_stack *stack)
{
	t_list	*curr;

	ft_printf("{head: %p, tail: %p, size: %zu}\n",
		stack->head,
		stack->tail,
		stack->size);
	curr = stack->head;
	while (curr)
	{
		ft_printf("%p: {next: %p, prev: %p, val: %d}\n", curr, curr->next,
			curr->prev, curr->value);
		curr = curr->next;
	}
}
*/

int	raise_error(void)
{
	ft_printf("ERROR\n");
	return (ERROR);
}

int	handle_stacks(t_stacks *stacks)
{
	int	res;

	res = 0;
	if (stacks->flags & SIMPLE)
		ft_printf("simple: not implemented\n");
	else if (stacks->flags & MEDIUM)
		res = medium(stacks);
	else if (stacks->flags & COMPLEX)
		ft_printf("complex: not implemented\n");
	else
		ft_printf("adaptive: not implemented\n");
	if (res == -1)
	{
		free_stacks(stacks, FREE_STACKS_ALL);
		return (raise_error());
	}
	if (stacks->flags & BENCH)
		bench(stacks, 0.5);
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
		free_stacks(stacks, FREE_STACKS_ALL);
		return (SUCCESS);
	}
	return (handle_stacks(stacks));
}
