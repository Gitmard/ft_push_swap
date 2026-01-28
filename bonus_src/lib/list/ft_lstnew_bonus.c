/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:39:58 by smenard           #+#    #+#             */
/*   Updated: 2026/01/28 11:34:56 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_bonus.h"

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = ft_calloc(1, sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	return (new);
}
