/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:39:30 by vquetier          #+#    #+#             */
/*   Updated: 2025/12/18 16:50:20 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_defines.h"

int	parse_flags(char *arg, t_args *args)
{
	if (ft_strcmp(arg, "--adaptive") == 0)
		args->flags |= ADAPTIVE;
	else if (ft_strcmp(arg, "--simple") == 0)
		args->flags |= SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		args->flags |= MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		args->flags |= COMPLEX;
	else if (ft_strcmp(arg, "--bench") == 0)
		args->flags |= BENCH;
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

int	parse_current(char *arg, t_args *args, t_set *set)
{
	if (ft_strncmp(arg, "--", 2) == 0)
	{
		if (parse_flags(arg, args) == ERROR)
			return (ERROR);
	}
	else
	{
		if (atoi_check(arg, args, set) == ERROR)
			return (ERROR);
	}
	return (SUCCES);
}

int	check_flags(t_args *args)
{
	uint32_t	flags;

	flags = ADAPTIVE | SIMPLE | MEDIUM | COMPLEX;
	if ((args->flags & flags) == ADAPTIVE)
		return (SUCCESS);
	if ((args->flags & flags) == SIMPLE)
		return (SUCCESS);
	if ((args->flags & flags) == MEDIUM)
		return (SUCCESS);
	if ((args->flags & flags) == COMPLEX)
		return (SUCCESS);
	if (args->flags == BENCH || args->flags == 0)
	{
		args->flags |= ADAPTIVE;
		return (SUCCESS);
	}
	return (ERROR);
}

t_args	*parse(int ac, char **av)
{
	t_args	*args;
	t_set	*set;
	int		i;

	if (create_ds(ac, &args, &set) == ERROR)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		if (parse_current(av[i], args, set) == ERROR)
		{
			free_set(set, FREE_SET_ALL);
			free_args(args, FREE_ARGS_ALL);
			return (NULL);
		}
		i++;
	}
	if (check_flags(args) == INVALID)
	{
		free_set(set, FREE_SET_ALL);
		free_args(args, FREE_ARGS_ALL);
		return (NULL);
	}
	free_set(set, FREE_SET_ALL);
	return (args);
}
