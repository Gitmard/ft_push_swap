/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:55:53 by vquetier          #+#    #+#             */
/*   Updated: 2025/12/17 15:45:26 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_args	*args;
	t_list	*list;

	args = parse(ac, av);
	if (!args || !args->stacks->stack_a->head)
	{
		__builtin_printf("ERROR EH OUI\n");
		return (1);
	}
	list = args->stacks->stack_a->head;
	while (list)
	{
		__builtin_printf("%d\n", list->value);
		list = list->next;
	}
	sa(args->stacks);
	list = args->stacks->stack_a->head;
	while (list)
	{
		__builtin_printf("%d\n", list->value);
		list = list->next;
	}
	sa(args->stacks);
	list = args->stacks->stack_a->head;
	while (list)
	{
		__builtin_printf("%d\n", list->value);
		list = list->next;
	}
	__builtin_printf("flags: %d, size: %zu\n", args->flags, args->stacks->stack_a->size);
	free_args(args, FREE_ARGS_ALL);
}
