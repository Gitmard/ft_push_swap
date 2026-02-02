/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:13:31 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/28 15:55:29 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	**get_op(void)
{
	char	**operations;

	operations = malloc(sizeof(char *) * 11);
	if (!operations)
		return (NULL);
	operations[0] = "pa\n";
	operations[1] = "pb\n";
	operations[2] = "ra\n";
	operations[3] = "rb\n";
	operations[4] = "rra\n";
	operations[5] = "rrb\n";
	operations[6] = "rr\n";
	operations[7] = "rrr\n";
	operations[8] = "sa\n";
	operations[9] = "sb\n";
	operations[10] = "ss\n";
	return (operations);
}

void	(**get_functions(void))(t_stacks *stacks)
{
	void	(**f)(t_stacks *stacks);

	f = malloc(sizeof(*f) * 11);
	if (!f)
		return (NULL);
	f[0] = &pa;
	f[1] = &pb;
	f[2] = &ra;
	f[3] = &rb;
	f[4] = &rra;
	f[5] = &rrb;
	f[6] = &rr;
	f[7] = &rrr;
	f[8] = &sa;
	f[9] = &sb;
	f[10] = &ss;
	return (f);
}
