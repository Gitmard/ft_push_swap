/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_set_defines_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:41:51 by smenard           #+#    #+#             */
/*   Updated: 2026/01/28 11:32:21 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_SET_DEFINES_BONUS_H
# define HASH_SET_DEFINES_BONUS_H

# include "hash_set_includes_bonus.h"

# define FREE_STRUCT 1
# define FREE_TABLE 2
# define FREE_USED 4
# define FREE_SET_ALL 7

typedef enum e_set_result
{
	SUCCESS,
	ALREADY_IN
}	t_set_result;

typedef struct s_set
{
	int			*table;
	bool		*used;
	uint32_t	size;
	uint32_t	mask;
}	t_set;

#endif
