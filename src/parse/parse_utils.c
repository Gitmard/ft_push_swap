/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:23:52 by vquetier          #+#    #+#             */
/*   Updated: 2025/12/17 14:50:43 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parse_defines.h"

int	add_in_struct(int value, t_args *args, t_set *set)
{
	if (add_in_set(set, value) == ALREADY_IN)
		return (ERROR);
	if (stack_add(args->stacks->stack_a, value) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	atoi_check(char *arg, t_args *args, t_set *set)
{
	long	ret;
	int		sign;
	int		i;

	if ((arg[0] == '+' || arg[0] == '-') && arg[1] == '\0')
		return (ERROR);
	ret = 0;
	sign = 1;
	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
	{
		if (arg[0] == '-')
			sign = -1;
		i++;
	}
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (ERROR);
		ret = ret * 10 + arg[i] - '0';
		if ((long)(int)ret < ret && ret * sign != INT_MIN)
			return (ERROR);
		i++;
	}
	return (add_in_struct((int)(ret * sign), args, set));
}

t_args	*create_args(void)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (!args)
		return (NULL);
	args->flags = 0;
	args->stacks = malloc(sizeof(t_stacks));
	if (!args->stacks)
		return (free_args(args, FREE_ARGS));
	args->stacks->combined_sizes = 0;
	args->stacks->stack_a = malloc(sizeof(t_stack));
	if (!args->stacks->stack_a)
		return (free_args(args, FREE_ARGS | FREE_STACKS));
	args->stacks->stack_b = malloc(sizeof(t_stack));
	if (!args->stacks->stack_b)
		return (free_args(args, FREE_ARGS | FREE_STACKS | FREE_A));
	args->stacks->stack_b->head = NULL;
	args->stacks->stack_b->tail = NULL;
	args->stacks->stack_b->size = 0;
	args->stacks->stack_a->head = NULL;
	args->stacks->stack_a->tail = NULL;
	args->stacks->stack_a->size = 0;
	return (args);
}

int	create_ds(int ac, t_args **args, t_set **set)
{
	if (ac == 1)
		return (ERROR);
	*args = create_args();
	if (!*args)
		return (ERROR);
	*set = create_set(ac - 1);
	if (!*set)
	{
		free_args(*args, FREE_ARGS_ALL);
		return (ERROR);
	}
	return (SUCCESS);
}

void	*free_args(t_args *args, uint32_t flag)
{
	if (flag & FREE_LISTS)
	{
		ft_lstclear(args->stacks->stack_a->head);
		ft_lstclear(args->stacks->stack_b->head);
	}
	if (flag & FREE_B)
		free(args->stacks->stack_b);
	if (flag & FREE_A)
		free(args->stacks->stack_a);
	if (flag & FREE_STACKS)
		free(args->stacks);
	if (flag & FREE_ARGS)
		free(args);
	return (NULL);
}
