/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_defines.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:12:50 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/07 15:55:17 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEDIUM_DEFINES_H
# define MEDIUM_DEFINES_H

# include "medium_includes.h"

int		ft_sqrt(int x);
void	update_poped(int w_start, int value, bool *poped, int *sorted);
void	update_window(int *w_start, int w_size, bool *poped, size_t size);
void	update_stacks(int w_start, int w_size, int *sorted, t_stacks *stacks);

# ifndef ERROR
#  define ERROR 1
# endif

# ifndef SUCCESS
#  define SUCCESS 0
# endif

#endif
