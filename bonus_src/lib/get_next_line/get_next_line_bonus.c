/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:52:21 by vquetier          #+#    #+#             */
/*   Updated: 2026/02/10 10:27:45 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_defines_bonus.h"

int	read_buffer(char buffer[BUFFER_SIZE], t_stack_gnl **stack)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE && !buffer[i])
		i++;
	if (i == BUFFER_SIZE)
		return (0);
	while (i < BUFFER_SIZE && buffer[i])
	{
		if (stack_append(stack, buffer[i]) == -1)
			return (-1);
		if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			return (1);
		}
		buffer[i] = '\0';
		i++;
	}
	if (i < BUFFER_SIZE)
		return (1);
	return (2);
}

char	*free_and_return(char *return_value, t_stack_gnl *stack,
		int res, int *gnl_code)
{
	t_stack_gnl	*current;
	t_stack_gnl	*next;

	*gnl_code = 0;
	if (stack && !return_value)
		*gnl_code = 1;
	if (res == -1)
		*gnl_code = 1;
	current = stack;
	while (current)
	{
		next = current->next;
		free(current->buffer);
		free(current);
		current = next;
	}
	return (return_value);
}

char	*create_line(t_stack_gnl *stack, size_t *i, size_t len)
{
	char	*line;
	size_t	index;
	size_t	j;

	if (stack)
		line = create_line(stack->next, &index, len + stack->index);
	else
	{
		*i = 0;
		return (malloc(sizeof(char) * (len + 1)));
	}
	if (i)
		*i = index;
	else if (line)
	{
		i = &index;
		line[(*i) + stack->index] = '\0';
	}
	if (!line)
		return (NULL);
	j = 0;
	while (j < stack->index)
		line[(*i)++] = stack->buffer[j++];
	return (line);
}

char	*get_next_line(int fd, int *gnl_code)
{
	static char	buffer[BUFFER_SIZE];
	t_stack_gnl	*stack;
	int			res;
	int			read_char;

	stack = NULL;
	res = 2;
	while (res == 2)
	{
		res = read_buffer(buffer, &stack);
		if (res == -1)
			return (free_and_return(NULL, stack, res, gnl_code));
		if (res == 1)
			read_char = 0;
		else
			read_char = read(fd, buffer, BUFFER_SIZE);
		if (read_char == -1)
			return (free_and_return(NULL, stack, read_char, gnl_code));
		if (res == 0 && read_char == 0 && !stack)
			return (free_and_return(NULL, stack, res, gnl_code));
		else if (res == 0 && !stack)
			res = 2;
	}
	return (free_and_return(create_line(stack, 0, 0), stack, res, gnl_code));
}
