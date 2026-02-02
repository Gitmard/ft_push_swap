/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:09:22 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/28 11:35:41 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_defines_bonus.h"

static t_block32	get_block(uint8_t b)
{
	uint8_t		i;
	uint8_t		shift;
	uint64_t	eight_bytes;
	t_block32	block;

	i = 0;
	shift = 0;
	eight_bytes = 0;
	while (i < 8)
	{
		eight_bytes |= ((uint64_t)b) << shift;
		shift += 8;
		i++;
	}
	block.a = eight_bytes;
	block.b = eight_bytes;
	block.c = eight_bytes;
	block.d = eight_bytes;
	return (block);
}

void	ft_memset(void *ptr, uint8_t b, size_t n)
{
	uint8_t		*end;
	uint8_t		*little;
	t_block32	*big;
	t_block32	block;

	end = (uint8_t *)ptr + n;
	little = (uint8_t *)ptr;
	block = get_block(b);
	while (((uintptr_t)little & 7) && little < end)
		*(little++) = b;
	big = (t_block32 *)little;
	while ((uint8_t *)(big + 1) <= end)
		*(big++) = block;
	little = (uint8_t *)big;
	while (little < end)
		*(little++) = b;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, size * nmemb);
	return (ptr);
}
