/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:41:46 by smenard           #+#    #+#             */
/*   Updated: 2026/01/27 13:54:38 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_includes.h"

void	print_stack(t_stack *stack)
{
	t_list	*curr;

	if (!stack)
	{
		ft_printf("(NULL)");
		return ;
	}
	curr = stack->head;
	while (curr)
	{
		ft_printf("{ value: %d, ", curr->value);
		ft_printf("target_index: %d }", curr->target_index);
		if (curr->next)
			ft_printf(" → ");
		curr = curr->next;
	}
}

void	print_stacks(t_stacks *stacks)
{
	ft_printf("Stack A :");
	print_stack(stacks->a);
	ft_printf("Stack B : ");
	print_stack(stacks->b);
	ft_printf("\n");
}
