/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:39:30 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/07 11:20:52 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parse_defines.h"

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

int	stack_add(t_stack *stack, int value)
{
	t_list	*new;

	new = ft_stackadd_new_tail(stack, value);
	if (!new)
		return (ERROR);
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

	if (create_ds(ac, &stacks, &set) == ERROR)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		if (parse_current(av[i], stacks, set) == ERROR)
		{
			free_set(set, FREE_SET_ALL);
			free_args(stacks, FREE_STACKS_ALL);
			return (NULL);
		}
		i++;
	}
	if (check_flags(stacks) == INVALID)
	{
		free_set(set, FREE_SET_ALL);
		free_args(stacks, FREE_STACKS_ALL);
		return (NULL);
	}
	free_set(set, FREE_SET_ALL);
	return (stacks);
}
