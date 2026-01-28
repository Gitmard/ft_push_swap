/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:39:30 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/28 13:30:31 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_defines_bonus.h"

int	parse_flags(char *arg, t_stacks *stacks)
{
	if (ft_strcmp(arg, "--adaptive") == 0)
		stacks->flags |= ADAPTIVE;
	else if (ft_strcmp(arg, "--simple") == 0)
		stacks->flags |= SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		stacks->flags |= MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		stacks->flags |= COMPLEX;
	else if (ft_strcmp(arg, "--bench") == 0)
		stacks->flags |= BENCH;
	else
		return (ERROR);
	return (SUCCESS);
}

int	stack_add(t_stacks *stacks, int value)
{
	if (!ft_stackadd_new_tail(stacks->a, value))
		return (ERROR);
	stacks->combined_sizes++;
	return (SUCCESS);
}

int	parse_current(char *arg, t_stacks *stacks, t_set *set)
{
	if (ft_strncmp(arg, "--", 2) == 0)
	{
		if (parse_flags(arg, stacks) == ERROR)
			return (ERROR);
	}
	else
	{
		if (atoi_check(arg, stacks, set) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

int	check_flags(t_stacks *stacks)
{
	uint32_t	flags;

	flags = ADAPTIVE | SIMPLE | MEDIUM | COMPLEX;
	if ((stacks->flags & flags) == ADAPTIVE)
		return (SUCCESS);
	if ((stacks->flags & flags) == SIMPLE)
		return (SUCCESS);
	if ((stacks->flags & flags) == MEDIUM)
		return (SUCCESS);
	if ((stacks->flags & flags) == COMPLEX)
		return (SUCCESS);
	if (stacks->flags == BENCH || stacks->flags == 0)
		return (SUCCESS);
	return (ERROR);
}

t_stacks	*parse(int ac, char **av)
{
	t_stacks	*stacks;
	t_set		*set;
	int			i;
	int			n_count;

	n_count = 0;
	if (normalise_args(&ac, &av, &n_count))
		return (NULL);
	if (create_ds(n_count, &stacks, &set) == ERROR)
	{
		free_split(av);
		return (NULL);
	}
	i = 0;
	while (i < ac)
	{
		if (parse_current(av[i], stacks, set) == ERROR)
			return (free_ds(set, stacks, av));
		i++;
	}
	if (check_flags(stacks) == INVALID)
		return (free_ds(set, stacks, av));
	free_set(set, FREE_SET_ALL);
	free_split(av);
	return (stacks);
}
