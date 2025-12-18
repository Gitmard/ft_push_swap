/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:55:53 by vquetier          #+#    #+#             */
/*   Updated: 2025/12/18 19:26:28 by smenard          ###   ########.fr       */
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
		ft_printf("ERROR EH OUI\n");
		return (1);
	}
	curr = args->stacks->stack_a->head;
	ft_printf("stack_a :{head: %p, tail: %p, size: %zu}\n",
		args->stacks->stack_a->head,
		args->stacks->stack_a->tail,
		args->stacks->stack_a->size);
	while (curr)
	{
		ft_printf("%p: {next: %p, prec: %p, val: %d}\n", curr,
			curr->next, curr->prev, curr->value);
		curr = curr->next;
	}
	free_args(args, FREE_ARGS_ALL);
}
