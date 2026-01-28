/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:09:49 by smenard           #+#    #+#             */
/*   Updated: 2025/12/18 19:20:06 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_lib.h"

static size_t	ft_skip_until_conversion(t_arg *arg, t_string str)
{
	size_t	j;

	j = 0;
	(void)arg;
	while (str[j] && !ft_strchr(CONVERSIONS, str[j]))
		j++;
	return (j);
}

static void	set_32bits_value(t_arg *arg, va_list ap)
{
	arg->value = ft_calloc(1, sizeof(int32_t));
	if (!arg->value)
		return ;
	*(int32_t *)(arg->value) = va_arg(ap, int32_t);
}

static void	set_64bits_value(t_arg *arg, va_list ap)
{
	arg->value = ft_calloc(1, (sizeof(int64_t)));
	if (!arg->value)
		return ;
	*(int64_t *)(arg->value) = va_arg(ap, int64_t);
}

static void	set_invalid_value(t_arg *arg)
{
	arg->type = INVALID;
	arg->value = NULL;
}

void	ft_parse_arg(t_string str, va_list ap, size_t *ptr_i, t_arg *arg)
{
	size_t	j;

	j = ft_skip_until_conversion(arg, str + 1);
	if (str[j])
		j++;
	arg->type = str[j];
	*ptr_i += j;
	if (arg->type == CHAR || arg->type == INT || arg->type == IINT
		|| arg->type == UINT || arg->type == LHEX || arg->type == UHEX)
		set_32bits_value(arg, ap);
	else if (arg->type == PTR || arg->type == STRING)
		set_64bits_value(arg, ap);
	else if (arg->type == PERCENT)
		arg->value = ft_strdup("%");
	else
		set_invalid_value(arg);
}
