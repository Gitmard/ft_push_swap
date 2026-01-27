/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:28:40 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/27 13:45:53 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "utils_includes.h"

/* check_sort.c */
bool	is_sorted(t_stacks *stacks);

/* sort.c */
int		*create_sorted_array(t_stacks *stacks);

/* print_stack.c */
void	print_stack(t_stack *stack);
void	print_stacks(t_stacks *stacks);

/* binary_search.c */
int		binary_search(int value, int *tab, int tab_len);

#endif
