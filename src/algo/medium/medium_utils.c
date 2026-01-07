/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:15:25 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/07 16:00:14 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "medium_defines.h"

int	ft_sqrt(int x)
{
	int	min;
	int	max;
	int	mid;

	min = 0;
	max = x + 1 / 2;
	while (max >= min)
	{
		mid = min + (max - min) / 2;
		if (mid * mid > x)
			max = mid - 1;
		else if (mid * mid < x)
			min = mid + 1;
		else
			return (mid);
	}
	if (x - (max * max) > (min * min) - x)
		return (min);
	return (max);
}

void	update_poped(int w_start, int value, bool *poped, int *sorted)
{
	int	i;

	i = w_start;
	while (sorted[i] != value)
		i++;
	poped[i] = true;
}

void	update_window(int *w_start, int w_size, bool *poped, size_t size)
{
	ft_printf("%d\n", size);
	while ((size_t)((*w_start) + w_size + 1) < size && poped[(*w_start)])
		(*w_start)++;
}

void	update_stacks(int w_start, int w_size, int *sorted, t_stacks *stacks)
{
	pb(stacks);
	if (stacks->b->head->value <= sorted[w_start + w_size / 2]
		&& stacks->b->size > 1)
		rb(stacks);
}
