/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:43:47 by smenard           #+#    #+#             */
/*   Updated: 2026/01/27 13:54:32 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_includes.h"

static void	fill_tab(int *to_fill, int *fill_with, int start, int end)
{
	int	i;

	i = start;
	while (i < end)
	{
		to_fill[i] = fill_with[i];
		i++;
	}
}

void	merge_sort(int *tab, int *temp_tab, int start, int end)
{
	int	split;
	int	i;
	int	j;
	int	k;

	if (end - start <= 1)
		return ;
	split = start + (end - start) / 2;
	merge_sort(tab, temp_tab, start, split);
	merge_sort(tab, temp_tab, split, end);
	i = start;
	j = split;
	k = start;
	while (k < end)
	{
		if (i < split && (j >= end || tab[i] < tab[j]))
			temp_tab[k++] = tab[i++];
		else
			temp_tab[k++] = tab[j++];
	}
	fill_tab(tab, temp_tab, start, end);
}

int	*create_sorted_array(t_stacks *stacks)
{
	t_list	*iter;
	int		*tab;
	int		*temp_tab;
	int		i;

	iter = stacks->a->head;
	tab = malloc(sizeof(int) * stacks->a->size);
	temp_tab = malloc(sizeof(int) * stacks->a->size);
	if (!tab || !temp_tab)
	{
		free(tab);
		free(temp_tab);
		return (NULL);
	}
	i = 0;
	while (iter)
	{
		tab[i] = iter->value;
		i++;
		iter = iter->next;
	}
	merge_sort(tab, temp_tab, 0, stacks->a->size);
	free(temp_tab);
	return (tab);
}
