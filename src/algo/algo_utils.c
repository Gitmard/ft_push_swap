/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:16:42 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/06 14:00:20 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "algo_utils_defines.h"

void	bubble_sort(int *tab, int size)
{
	int	i;
	int	tmp;

	while (size > 1)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		size--;
	}
}

int	*create_sorted_array(t_stacks *stacks)
{
	t_list	*iter;
	int	*tab;
	int	i;

	iter = stacks->stack_a->head;
	tab = malloc(sizeof(int) * stacks->stack_a->size);
	if (!tab)
		return (NULL);
	i = 0;
	while (iter)
	{
		tab[i] = iter->value;
		i++;
		iter = iter->next;
	}
	bubble_sort(tab, stacks->stack_a->size);
}
