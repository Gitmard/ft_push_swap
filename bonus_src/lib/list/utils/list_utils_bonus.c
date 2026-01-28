/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:21:08 by smenard           #+#    #+#             */
/*   Updated: 2026/01/28 11:34:34 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_includes_bonus.h"

t_list	*reset_link(t_list *link)
{
	if (!link)
		return (NULL);
	link->prev = NULL;
	link->next = NULL;
	return (link);
}
