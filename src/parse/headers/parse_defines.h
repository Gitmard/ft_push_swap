/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_defines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:42:49 by vquetier          #+#    #+#             */
/*   Updated: 2025/12/17 14:51:07 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_DEFINES_H
# define PARSE_DEFINES_H

# include "parse_includes.h"

# define FREE_ARGS 1
# define FREE_STACKS 2
# define FREE_A 4
# define FREE_B 8
# define FREE_LISTS 16
# define FREE_ARGS_ALL 31

# define ADAPTIVE 1
# define SIMPLE 2
# define MEDIUM 4
# define COMPLEX 8
# define BENCH 16

# define SUCCES 0
# define ERROR 1

# define INVALID 1

typedef struct s_args
{
	t_stacks	*stacks;
	uint32_t	flags;
}	t_args;

void	*free_args(t_args *args, uint32_t flag);
int		create_ds(int ac, t_args **args, t_set **set);
int		atoi_check(char *arg, t_args *args, t_set *set);
int		stack_add(t_stack *stack, int value);

int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);

#endif
