/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_defines_bonus.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:32:30 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/28 11:29:53 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_DEFINES_BONUS_H
# define GET_NEXT_LINE_DEFINES_BONUS_H

# include "get_next_line_includes_bonus.h"

typedef struct s_stack_gnl
{
	char				*buffer;
	size_t				index;
	struct s_stack_gnl	*next;
}	t_stack_gnl;

int	stack_append(t_stack_gnl **stack, char c);

# ifndef STACK_BUFFER_SIZE
#  define STACK_BUFFER_SIZE 4096
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

#endif
