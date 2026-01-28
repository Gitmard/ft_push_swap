/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:58:00 by smenard           #+#    #+#             */
/*   Updated: 2025/12/18 16:08:50 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*ft_stacknew(void)
{
	t_stack	*new_stack;

	new_stack = ft_calloc(1, sizeof(t_stack));
	return (new_stack);
}
