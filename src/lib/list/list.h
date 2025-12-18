/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:10:00 by smenard           #+#    #+#             */
/*   Updated: 2025/12/16 16:21:10 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "lib_defines.h"
# include "lib.h"

/* ft_lstnew.c */
t_list	*ft_lstnew(int value, size_t *size);

/* ft_lstadd.c */
t_list	*ft_lstadd_new_head(t_list *lst, int value);

t_list	*ft_lstadd_head(t_list *lst, t_list *new);

t_list	*ft_lstadd_new_tail(t_list *lst, int value);

t_list	*ft_lstadd_tail(t_list *lst, t_list *new);

/* ft_lstremove.c */
t_list	*ft_lstremove_head(t_list *lst);

t_list	*ft_lstremove_tail(t_list *lst);

/* ft_lstclear.c */
void	*ft_lstclear(t_list *lst_start);

#endif
