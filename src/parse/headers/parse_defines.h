/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_defines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:42:49 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/07 11:32:18 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_DEFINES_H
# define PARSE_DEFINES_H

# include "parse_includes.h"

# define FREE_STACKS 1
# define FREE_A 2
# define FREE_B 4
# define FREE_LISTS 8
# define FREE_STACKS_ALL 15

# define ADAPTIVE 1
# define SIMPLE 2
# define MEDIUM 4
# define COMPLEX 8
# define BENCH 16

# define SUCCESS 0
# define ERROR 1

# define INVALID 1

void	*free_stacks(t_stacks *stacks, uint32_t flag);
int		create_ds(int ac, t_stacks **stacks, t_set **set);
int		atoi_check(char *arg, t_stacks *stacks, t_set *set);
int		stack_add(t_stack *stack, int value);

int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);

#endif
