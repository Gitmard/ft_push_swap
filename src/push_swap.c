/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:55:53 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/07 14:53:16 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

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

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	int			steps;

	stacks = parse(ac, av);
	if (!stacks || !stacks->a->head)
	{
		ft_printf("Error\n");
		return (1);
	}
	print_stack(stacks->a);
	steps = medium(stacks);
	print_stack(stacks->a);
	ft_printf("%d\n", steps);
	free_stacks(stacks, FREE_STACKS_ALL);
}
