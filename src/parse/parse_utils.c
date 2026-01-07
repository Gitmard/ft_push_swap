/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:23:52 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/07 11:31:19 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parse_defines.h"

void	*free_stacks(t_stacks *stacks, uint32_t flag)
{
	if (flag & FREE_LISTS)
	{
		ft_lstclear(stacks->a->head);
		ft_lstclear(stacks->b->head);
	}
	if (flag & FREE_B)
		free(stacks->b);
	if (flag & FREE_A)
		free(stacks->a);
	if (flag & FREE_STACKS)
		free(stacks);
	return (NULL);
}

int	add_in_struct(int value, t_stacks *stacks, t_set *set)
{
	if (add_in_set(set, value) == ALREADY_IN)
		return (ERROR);
	if (stack_add(stacks->a, value) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	atoi_check(char *arg, t_stacks *stacks, t_set *set)
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
	return (add_in_struct((int)(ret * sign), stacks, set));
}

t_stacks	*create_stacks(void)
{
	t_stacks *stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->flags = 0;
	stacks->combined_sizes = 0;
	stacks->a = malloc(sizeof(t_stack));
	if (!stacks->a)
		return (free_stacks(stacks, FREE_STACKS));
	stacks->b = malloc(sizeof(t_stack));
	if (!stacks->b)
		return (free_stacks(stacks, FREE_STACKS | FREE_A));
	stacks->b->head = NULL;
	stacks->b->tail = NULL;
	stacks->b->size = 0;
	stacks->a->head = NULL;
	stacks->a->tail = NULL;
	stacks->a->size = 0;
	return (stacks);
}

int	create_ds(int ac, t_stacks **stacks, t_set **set)
{
	if (ac == 1)
		return (ERROR);
	*stacks = create_stacks();
	if (!*stacks)
		return (ERROR);
	*set = create_set(ac - 1);
	if (!*set)
	{
		free_stacks(*stacks, FREE_STACKS_ALL);
		return (ERROR);
	}
	return (SUCCESS);
}
