/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:03:29 by vquetier          #+#    #+#             */
/*   Updated: 2025/12/16 13:25:36 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hash_set_includes.h"
#include "hash_set_defines.h"

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
	uint32_t	lowest_size;
	uint32_t	set_size;
	t_set		*set;

	lowest_size = stack_size + (stack_size + 1) / 2;
	set_size = 1;
	while (set_size < lowest_size)
		set_size *= 2;
	set = malloc(sizeof(t_set));
	if (!set)
		return (NULL);
	set->table = ft_calloc(set_size, sizeof(int));
	if (!set->table)
	{
		free_set(set, FREE_STRUCT);
		return (NULL);
	}
	set->used = ft_calloc(set_size, sizeof(bool));
	if (!set->used)
	{
		free_set(set, FREE_STRUCT | FREE_TABLE);
		return (NULL);
	}
	set->size = set_size;
	set->mask = set_size - 1;
	return (set);
}
