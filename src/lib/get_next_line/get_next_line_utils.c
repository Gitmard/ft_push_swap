/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:57:10 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/13 13:37:45 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_defines.h"

t_stack_gnl	*create_stack_elem(t_stack_gnl *next)
{
	t_stack_gnl	*new;

	new = malloc(sizeof(t_stack_gnl));
	if (!new)
		return (NULL);
	new->buffer = malloc(sizeof(char) * STACK_BUFFER_SIZE);
	if (!new->buffer)
	{
		free(new);
		return (NULL);
	}
	new->index = 0;
	new->next = next;
	return (new);
}

int	stack_append(t_stack_gnl **stack, char c)
{
	t_stack_gnl	*new;

	if (!*stack || (*stack)->index >= STACK_BUFFER_SIZE)
	{
		new = create_stack_elem(*stack);
		if (!new)
			return (-1);
		*stack = new;
	}
	(*stack)->buffer[(*stack)->index++] = c;
	return (0);
}
