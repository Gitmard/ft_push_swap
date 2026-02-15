/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:01:04 by vquetier          #+#    #+#             */
/*   Updated: 2026/02/15 13:03:48 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "instructions_bonus.h"
# include "lib_bonus.h"
# include "parse_bonus.h"
# include <unistd.h>

void	raise_error_checker(void);
void	(**get_functions(void))(t_stacks *stacks);
void	clean_exit(t_stacks *stacks, uint32_t flags, int value);

#endif
