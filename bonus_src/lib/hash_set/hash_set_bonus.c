/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_set_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:03:29 by vquetier          #+#    #+#             */
/*   Updated: 2026/02/02 15:51:11 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_set_includes_bonus.h"
#include "hash_set_defines_bonus.h"

void	free_set(t_set *set, uint32_t flag)
{
	if (!set)
		return ;
	if (flag & FREE_TABLE)
		free(set->table);
	if (flag & FREE_USED)
		free(set->used);
	if (flag & FREE_STRUCT)
		free(set);
}

static uint32_t	hash_function(int key)
{
	uint32_t	hash;

	hash = (uint32_t)key;
	hash ^= hash >> 16;
	hash *= 0x7feb352d;
	hash ^= hash >> 15;
	return (hash);
}

t_set_result	add_in_set(t_set *set, int key)
{
	uint32_t	hash;
	uint32_t	perturb;
	uint32_t	i;

	hash = hash_function(key);
	perturb = hash;
	i = hash & set->mask;
	while (set->used[i] && set->table[i] != key)
	{
		i = (i * 5 + 1 + perturb) & set->mask;
		perturb >>= 5;
	}
	if (set->used[i])
		return (ALREADY_IN);
	set->table[i] = key;
	set->used[i] = true;
	return (SUCCESS);
}

t_set	*create_set(uint32_t stack_size)
{
	t_set		*set;
	uint32_t	lowest_size;

	set = ft_calloc(1, sizeof(t_set));
	if (!set)
		return (NULL);
	lowest_size = stack_size + (stack_size + 1) / 2;
	set->size = 1;
	while (set->size < lowest_size)
		set->size *= 2;
	set->table = ft_calloc(set->size, sizeof(int));
	if (!set->table)
	{
		free_set(set, FREE_STRUCT);
		return (NULL);
	}
	set->used = ft_calloc(set->size, sizeof(bool));
	if (!set->used)
	{
		free_set(set, FREE_STRUCT | FREE_TABLE);
		return (NULL);
	}
	set->mask = set->size - 1;
	return (set);
}
