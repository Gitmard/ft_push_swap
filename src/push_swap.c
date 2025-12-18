/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:55:53 by vquetier          #+#    #+#             */
/*   Updated: 2025/12/18 20:13:45 by smenard          ###   ########.fr       */
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
		ft_printf("%p: {next: %p, prec: %p, val: %d}\n", curr, curr->next,
			curr->prev, curr->value);
		curr = curr->next;
	}
}

int	main(int ac, char **av)
{
	t_args	*args;

	args = parse(ac, av);
	if (!args || !args->stacks->stack_a->head)
	{
		ft_printf("ERROR EH OUI\n");
		return (1);
	}
	print_stack(args->stacks->stack_a);
	swap_a(args->stacks);
	ft_printf("AFTER sa :\n");
	print_stack(args->stacks->stack_a);
	push_b(args->stacks);
	push_b(args->stacks);
	ft_printf("AFTER 2 pb, stack_a :\n");
	print_stack(args->stacks->stack_a);
	ft_printf("stack_b :\n");
	print_stack(args->stacks->stack_b);
	free_args(args, FREE_ARGS_ALL);
}
