/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:01:04 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/28 13:29:18 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "parse_bonus.h"
# include "instructions_bonus.h"
# include "lib_bonus.h"
# include <unistd.h>

void	(**get_functions(void))(t_stacks *stacks);
char	**get_op(void);

# define NO_DRAIN 0
# define DRAIN_STDIN 1

#endif
