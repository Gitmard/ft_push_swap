/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:27:19 by smenard           #+#    #+#             */
/*   Updated: 2026/01/28 11:34:46 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_bonus.h"

void	*ft_lstclear(t_list *lst)
{
	if (!lst)
		return (NULL);
	ft_lstclear(lst->next);
	free(lst);
	return (NULL);
}
