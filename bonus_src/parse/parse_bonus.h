/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:32:30 by smenard           #+#    #+#             */
/*   Updated: 2026/01/28 11:42:41 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_BONUS_H
# define PARSE_BONUS_H

# include "parse_defines_bonus.h"

t_stacks	*parse(int ac, char **av);
void		*free_stacks(t_stacks *stacks, uint32_t flag);

#endif
