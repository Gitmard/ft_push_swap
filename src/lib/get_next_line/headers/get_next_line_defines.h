/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_defines.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:32:30 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/13 13:37:25 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_DEFINES_H
# define GET_NEXT_LINE_DEFINES_H

# include "get_next_line_includes.h"

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
