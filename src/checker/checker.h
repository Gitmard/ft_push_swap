/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:01:04 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/13 13:43:07 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "parse.h"
# include "instructions.h"
# include "lib.h"

void	(**get_functions(void))(t_stacks *stacks);
char	**get_op(void);

# define NO_DRAIN 0
# define DRAIN_STDIN 1

#endif
