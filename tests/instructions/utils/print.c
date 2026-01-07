/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:18:13 by smenard           #+#    #+#             */
/*   Updated: 2026/01/07 17:13:12 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_tests_instructions.h"

void	print_stack(t_stack *stack)
{
	t_list	*curr;

	if (!stack)
	{
		printf("(NULL)");
		return ;
	}
	curr = stack->head;
	while (curr)
	{
		printf("%d", curr->value);
		if (curr->next)
			printf("→");
		curr = curr->next;
	}
}

void	print_stacks(t_stacks *stacks)
{
	printf("Stack A :");
	print_stack(stacks->a);
	printf("Stack B : ");
	print_stack(stacks->b);
	printf("\n");
}