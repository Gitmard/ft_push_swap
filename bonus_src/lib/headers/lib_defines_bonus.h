/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_defines_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:18:22 by smenard           #+#    #+#             */
/*   Updated: 2026/01/28 11:33:17 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_DEFINES_BONUS_H
# define LIB_DEFINES_BONUS_H

# include "lib_includes_bonus.h"

# define NO_PRINT 32

typedef struct s_op
{
	size_t	total;
	size_t	sa;
	size_t	sb;
	size_t	ss;
	size_t	pa;
	size_t	pb;
	size_t	ra;
	size_t	rb;
	size_t	rr;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
}			t_op;

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				value;
	uint32_t		target_index;
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
	t_op			op;
	int				flags;
}					t_stacks;

#endif
