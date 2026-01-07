/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:39:30 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/07 17:15:31 by vquetier         ###   ########lyon.fr   */
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

int	count_words(char *arg)
{
	bool	flag;
	int		count;
	int		i;

	flag = true;
	count = 0;
	i = 0;
	while (arg[i])
	{
		if (arg[i] == ' ')
			flag = true;
		else if (flag)
			count++;
		i++;
	}
	return (count);
}

int	count_full_words(int ac, char **av)
{
	int	words_count;
	int	i;

	words_count = 1;
	i = 1;
	while (i < ac)
	{
		words_count += count_words(av[i]);
		i++;
	}
	return (words_count);
}

int	normalise_args(int &ac, char ***av, int &n_count)
{
	int		words_count;
	char	**split;
	bool	flag;
	int		i;
	int		j;

	words_count = count_full_words(*ac, *av);
	split = malloc(sizeof(char *) * words_count);
	if (!split)
		return (1);
	i = 0;
	j = 0;
	while (i < words_count)
	{
		split[i] = create_words((*av)[])
	}
}

t_stacks	*parse(int ac, char **av)
{
	t_stacks	*stacks;
	t_set		*set;
	int			i;
	int			n_count;

	if (normalise_args(&ac, &av, &n_count))
		return (NULL);
	if (create_ds(n_count, &stacks, &set) == ERROR)
		return (free_args(av, ac));
	i = 1;
	while (i < ac)
	{
		if (parse_current(av[i], stacks, set) == ERROR)
		{
			free_set(set, FREE_SET_ALL);
			free_stacks(stacks, FREE_STACKS_ALL);
			return (NULL);
		}
		i++;
	}
	if (check_flags(stacks) == INVALID)
	{
		free_set(set, FREE_SET_ALL);
		free_stacks(stacks, FREE_STACKS_ALL);
		return (NULL);
	}
	free_set(set, FREE_SET_ALL);
	return (stacks);
}
