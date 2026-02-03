/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:10:00 by smenard           #+#    #+#             */
/*   Updated: 2026/01/28 11:35:12 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_BONUS_H
# define LIST_BONUS_H

# include "list_includes_bonus.h"

/* ft_lstnew.c */
t_list	*ft_lstnew(int value);

/* ft_lstadd.c */
t_list	*ft_lstadd_head(t_list *lst, t_list *new);

t_list	*ft_lstadd_tail(t_list *lst, t_list *new);

/* ft_lstremove.c */
t_list	*ft_lstremove_head(t_list *lst);

t_list	*ft_lstremove_tail(t_list *lst);

/* ft_lstclear.c */
void	*ft_lstclear(t_list *lst_start);

#endif
