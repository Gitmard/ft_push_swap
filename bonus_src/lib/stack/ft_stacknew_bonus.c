/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:58:00 by smenard           #+#    #+#             */
/*   Updated: 2026/01/28 11:37:43 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_bonus.h"

t_stack	*ft_stacknew(void)
{
	t_stack	*new_stack;

	new_stack = ft_calloc(1, sizeof(t_stack));
	return (new_stack);
}
