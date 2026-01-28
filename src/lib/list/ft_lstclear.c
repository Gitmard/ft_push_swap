/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:27:19 by smenard           #+#    #+#             */
/*   Updated: 2025/12/18 14:55:29 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	*ft_lstclear(t_list *lst)
{
	if (!lst)
		return (NULL);
	ft_lstclear(lst->next);
	free(lst);
	return (NULL);
}
