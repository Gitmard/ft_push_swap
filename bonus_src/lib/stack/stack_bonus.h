/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:01:45 by smenard           #+#    #+#             */
/*   Updated: 2026/02/03 14:22:12 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_BONUS_H
# define STACK_BONUS_H

# include "stack_includes_bonus.h"

/* ft_stackadd_bonus.c */
t_list	*ft_stackadd_head(t_stack *stack, t_list *new_head);

t_list	*ft_stackadd_new_tail(t_stack *stack, int value);

t_list	*ft_stackadd_tail(t_stack *stack, t_list *new_tail);

/* ft_stackremove_bonus.c */
t_list	*ft_stackremove_head(t_stack *stack);

t_list	*ft_stackremove_tail(t_stack *stack);

/* get_previous_value_bonus.c */
t_list	*get_previous_node(t_list *current, t_list *tail);

#endif
