/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:29:08 by smenard           #+#    #+#             */
/*   Updated: 2026/01/07 17:13:12 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_tests_instructions.h"
#include "lib_tests_instructions.h"
#include "instructions.h"

void	tests_instructions_push(void)
{
	t_stacks *stacks;

	stacks = calloc(1, sizeof(t_stacks));
	stacks->a = ft_stacknew();
	stacks->b = ft_stacknew();

	printf("TESTS FOR EMPTY STACK A\\n");
	pb(stacks);
	printf("PROUTXD\n");
	print_stacks(stacks);
	pa(stacks);
	print_stacks(stacks);

	printf("TESTS FOR STACK A = 0 → 1 → 2 → 3 → 4\n");
	for (int i = 0; i < 5; i++)
		ft_stackadd_new_tail(stacks->a, i);
	pb(stacks);
	print_stacks(stacks);
	pa(stacks);
	print_stacks(stacks);

	printf("5x pb \n");
	for (int i = 0; i < 5; i++)
		pb(stacks);
	print_stacks(stacks);
}