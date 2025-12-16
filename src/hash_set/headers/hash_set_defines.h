/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_set_defines.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:41:51 by smenard           #+#    #+#             */
/*   Updated: 2025/12/16 13:22:11 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_SET_DEFINES_H
# define HASH_SET_DEFINES_H

# include "hash_set_includes.h"

# define FREE_STRUCT 1
# define FREE_TABLE 1 << 1
# define FREE_USED 1 << 2

typedef enum e_set_result
{
	SUCCESS,
	ALREADY_IN
}	t_set_result;

typedef struct s_set
{
        int		*table;
	bool		*used;
        uint32_t	size;
        uint32_t	mask;
}	t_set;

#endif
