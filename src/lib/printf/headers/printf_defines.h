/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_defines.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:51:05 by smenard           #+#    #+#             */
/*   Updated: 2026/02/03 14:17:43 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_DEFINES_H
# define PRINTF_DEFINES_H

# include "printf_includes.h"

# define DEC_CHARSET "0123456789"
# define LHEX_CHARSET "0123456789abcdef"
# define UHEX_CHARSET "0123456789ABCDEF"

# define FLAGS "-0.# +"
# define CONVERSIONS "cspdiuxX%"

typedef char		*t_string;

typedef enum e_value_type
{
	INVALID = '\0',
	CHAR = 'c',
	STRING = 's',
	INT = 'd',
	IINT = 'i',
	UINT = 'u',
	LHEX = 'x',
	UHEX = 'X',
	PTR = 'p',
	PERCENT = '%'
}					t_value_type;

typedef struct s_arg
{
	void			*value;
	t_value_type	type;
}					t_arg;

#endif
