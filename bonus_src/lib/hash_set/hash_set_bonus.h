/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_set_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:32:27 by smenard           #+#    #+#             */
/*   Updated: 2026/01/28 11:33:02 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_SET_BONUS_H
# define HASH_SET_BONUS_H

# include "hash_set_defines_bonus.h"

t_set			*create_set(uint32_t size);
void			free_set(t_set *set, uint32_t flag);
t_set_result	add_in_set(t_set *set, int key);

#endif
