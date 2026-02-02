/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_defines.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:12:50 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/28 12:55:45 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEDIUM_DEFINES_H
# define MEDIUM_DEFINES_H

# include "medium_includes.h"

void	update_stacks(uint32_t w_start, uint32_t w_size,
			t_stacks *stacks);
void	update_window(uint32_t *w_start, uint32_t w_size,
			bool *poped, size_t size);
void	ensure_w_size_is_correct(uint32_t *w_size, uint32_t w_start,
			uint32_t full_size);

# ifndef ERROR
#  define ERROR 1
# endif

# ifndef SUCCESS
#  define SUCCESS 0
# endif

#endif
