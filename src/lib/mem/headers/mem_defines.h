/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_defines.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:17:15 by vquetier          #+#    #+#             */
/*   Updated: 2025/12/16 15:36:14 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_DEFINES_H
# define MEM_DEFINES_H

# include "mem_includes.h"

typedef struct s_block32
{
	uint64_t	a;
	uint64_t	b;
	uint64_t	c;
	uint64_t	d;
}	t_block32;

#endif
