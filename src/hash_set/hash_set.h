/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_set.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:32:27 by smenard           #+#    #+#             */
/*   Updated: 2025/12/16 13:39:03 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_SET_H
# define HASH_SET_H

# include "hash_set_defines.h"

t_set			*create_set(uint32_t size);
void			free_set(t_set *set, uint32_t flag);
t_set_result	add_in_set(t_set *set, int key);

#endif
