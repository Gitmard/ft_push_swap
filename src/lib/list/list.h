/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:10:00 by smenard           #+#    #+#             */
/*   Updated: 2025/12/18 15:25:36 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "list_includes.h"

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
