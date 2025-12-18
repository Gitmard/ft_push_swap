/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:55:53 by vquetier          #+#    #+#             */
/*   Updated: 2025/12/18 17:08:49 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_args	*args;
	t_list	*curr;

	args = parse(ac, av);
	if (!args || !args->stacks->stack_a->head)
	{
		__builtin_printf("ERROR EH OUI\n");
		return (1);
	}
	curr = args->stacks->stack_a->head;
	__builtin_printf("stack_a :{head: %p, tail: %p, size: %zu}\n",
		args->stacks->stack_a->head,
		args->stacks->stack_a->tail,
		args->stacks->stack_a->size);
	while (curr)
	{
		__builtin_printf("%p: {next: %p, prec: %p, val: %d}\n", curr,
			curr->next, curr->prev, curr->value);
		curr = curr->next;
	}
	free_args(args, FREE_ARGS_ALL);
}
