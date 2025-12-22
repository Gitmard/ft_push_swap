/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_previous.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:34:09 by smenard           #+#    #+#             */
/*   Updated: 2026/01/13 11:02:14 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_includes.h"

t_list	*get_previous_node(t_list *current, t_list *tail)
{
	if (!current)
		return (NULL);
	if (!current->prev)
		return (tail);
	return (current->prev);
}
