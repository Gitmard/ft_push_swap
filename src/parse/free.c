/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:18:06 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/09 11:18:15 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parse_defines.h"

int	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (ERROR);
}

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

void	*free_ds(t_set *set, t_stacks *stacks, char **split)
{
	free_set(set, FREE_SET_ALL);
	free_stacks(stacks, FREE_STACKS_ALL);
	free_split(split);
	return (NULL);
}
