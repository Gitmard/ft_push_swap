/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:00:36 by vquetier          #+#    #+#             */
/*   Updated: 2026/02/16 14:20:57 by smenard          ###   ########.fr       */
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

int	execute_op(t_stacks *stacks, char *line, char **operations,
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
		clean_exit(stacks, RAISE_ERROR, 1);
	if (stacks->flags != 0)
		clean_exit(stacks, FREE_STACKS_ALL | RAISE_ERROR, 1);
	if (!stacks->combined_sizes)
		clean_exit(stacks, FREE_STACKS_ALL, 0);
	if (handle_operations(stacks, get_op(), get_functions()) == ERROR)
		clean_exit(stacks, FREE_STACKS_ALL | RAISE_ERROR, 1);
	if (is_sorted(stacks))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clean_exit(stacks, FREE_STACKS_ALL, 0);
}
