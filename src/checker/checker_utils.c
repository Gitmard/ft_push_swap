/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:13:31 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/13 13:43:27 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**get_op(void)
{
	char	**operations;

	operations = malloc(sizeof(char *) * 11);
	if (!operations)
		return (NULL);
	operations[0] = "pa";
	operations[1] = "pb";
	operations[2] = "ra";
	operations[3] = "rb";
	operations[4] = "rra";
	operations[5] = "rrb";
	operations[6] = "rr";
	operations[7] = "rrr";
	operations[8] = "sa";
	operations[9] = "sb";
	operations[10] = "ss";
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
