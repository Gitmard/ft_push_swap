/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_defines.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:18:22 by smenard           #+#    #+#             */
/*   Updated: 2025/12/18 16:08:49 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_DEFINES_H
# define LIB_DEFINES_H

# include "lib_includes.h"

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				value;
}					t_list;

typedef struct s_stack
{
	t_list			*head;
	t_list			*tail;
	size_t			size;
}					t_stack;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
	size_t			combined_sizes;
	uint32_t		flags
}					t_stacks;

#endif
