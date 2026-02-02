/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:00:36 by vquetier          #+#    #+#             */
/*   Updated: 2026/02/02 17:21:46 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	raise_error_checker(void)
{
	char	buffer[256];
	int		rd_char;

	write(2, "Error\n", 6);
	rd_char = read(0, buffer, 256);
	while (rd_char > 0)
		rd_char = read(0, buffer, 256);
	return (1);
}

static int	execute_op(t_stacks *stacks, char *line, char **operations,
		void (**f)(t_stacks *stacks))
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (ft_strcmp(line, operations[i]) == 0)
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

static int	handle_operations(t_stacks *stacks, char **operations,
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
		return (raise_error_checker());
	if (stacks->flags != 0)
	{
		free_stacks(stacks, FREE_STACKS_ALL);
		return (raise_error_checker());
	}
	if (handle_operations(stacks, get_op(), get_functions()))
	{
		free_stacks(stacks, FREE_STACKS_ALL);
		return (raise_error_checker());
	}
	if (is_sorted(stacks))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(stacks, FREE_STACKS_ALL);
	return (0);
}
