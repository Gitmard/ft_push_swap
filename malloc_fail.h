/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_fail.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:20:01 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/31 14:35:09 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_FAIL_H
# define MALLOC_FAIL_H

# include <stdlib.h>
# include <stddef.h>

# ifndef FAIL
#  define FAIL 10
# endif

void    *ft_malloc(size_t size);

#endif
