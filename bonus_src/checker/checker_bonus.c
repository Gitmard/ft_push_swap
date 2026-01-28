/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:00:36 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/28 15:27:22 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdio.h>

int	raise_error_checker(int flag)
{
	char	buffer[256];
	int		rd_char;

	write(2, "Error\n", 6);
	if (flag == DRAIN_STDIN)
	{
		rd_char = read(0, buffer, 256);
		while (rd_char > 0)
			rd_char = read(0, buffer, 256);
	}
	return (1);
}

int	comp_len(char *line, char *op)
{
	int	line_len;
	int	op_len;

	line_len = 0;
	while (line[line_len] && line[line_len] != '\n')
		line_len++;
	op_len = 0;
	while (op[op_len])
		op_len++;
	if (op_len > line_len)
		return (op_len);
	return (line_len);
}

int	execute_op(t_stacks *stacks, char *line, char **operations,
		void (**f)(t_stacks *stacks))
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (ft_strncmp(line, operations[i],
				comp_len(line, operations[i])) == 0)
		{
			f[i](stacks);
			break ;
		}
		i++;
	}
	if (i == 11)
		return (1);
	return (0);
}

int	handle_operations(t_stacks *stacks, char **operations,
		void (**f)(t_stacks *stacks))
{
	char	*line;
	int		ret;
	int		gnl_code;

	ret = 0;
	gnl_code = 1;
	if (!operations || !f)
		ret = 1;
	line = "dummy";
	while (line && ret == 0)
	{
		line = get_next_line(0, &gnl_code);
		if (line)
			ret = execute_op(stacks, line, operations, f);
		free(line);
	}
	if (gnl_code)
		ret = 1;
	free(operations);
	free(f);
	return (ret);
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	stacks = parse(ac, av);
	if (!stacks)
		return (raise_error_checker(NO_DRAIN));
	if (stacks->flags != 0)
	{
		free_stacks(stacks, FREE_STACKS_ALL);
		return (raise_error_checker(NO_DRAIN));
	}
	stacks->flags = NO_PRINT;
	if (handle_operations(stacks, get_op(), get_functions()))
	{
		free_stacks(stacks, FREE_STACKS_ALL);
		return (raise_error_checker(NO_DRAIN));
	}
	if (is_sorted(stacks))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(stacks, FREE_STACKS_ALL);
	return (0);
}
