/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:09:42 by smenard           #+#    #+#             */
/*   Updated: 2025/12/18 19:20:01 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_lib.h"

ssize_t	ft_putstr(t_string str)
{
	size_t	len;

	if (str == NULL)
		return (write(STDOUT_FILENO, "(null)", 6));
	len = ft_strlen(str);
	return (write(STDOUT_FILENO, str, len));
}

ssize_t	ft_putnbr_base_signed(int64_t num, t_string base)
{
	ssize_t	total_write_count;

	total_write_count = 0;
	if (num < 0)
	{
		total_write_count++;
		write(STDOUT_FILENO, "-", 1);
	}
	return (ft_putnbr_base(ft_abs(num), base) + total_write_count);
}

ssize_t	ft_putnbr_base(uint64_t num, t_string base)
{
	size_t	base_len;
	ssize_t	write_result;
	ssize_t	total_write_count;
	char	c;

	base_len = ft_strlen(base);
	if (base_len == 0)
		return (0);
	write_result = 0;
	total_write_count = 0;
	if (num >= base_len)
	{
		write_result = ft_putnbr_base(num / base_len, base);
		if (write_result == -1)
			return (-1);
		total_write_count += write_result;
		c = base[num % base_len];
		write_result = write(STDOUT_FILENO, &c, 1);
		return (write_result + total_write_count);
	}
	c = base[num % base_len];
	write_result = write(STDOUT_FILENO, &c, 1);
	if (write_result == -1)
		return (-1);
	return (write_result + total_write_count);
}

ssize_t	ft_print_arg(t_arg arg)
{
	if ((arg.type == PTR || arg.type == STRING) && arg.value
		&& (*(void **)arg.value == NULL))
	{
		if (arg.type == PTR)
			return (ft_putstr("(nil)"));
		else if (arg.type == STRING)
			return (ft_putstr("(null)"));
	}
	if (arg.type == CHAR || arg.type == PERCENT)
		return (write(STDOUT_FILENO, arg.value, 1));
	else if (arg.type == STRING)
		return (ft_putstr(*(t_string *)arg.value));
	else if (arg.type == INT || arg.type == IINT)
		return (ft_putnbr_base_signed(*((int32_t *)arg.value), DEC_CHARSET));
	else if (arg.type == UINT)
		return (ft_putnbr_base(*(uint32_t *)arg.value, DEC_CHARSET));
	else if (arg.type == LHEX)
		return (ft_putnbr_base_signed(*(uint32_t *)arg.value, LHEX_CHARSET));
	else if (arg.type == UHEX)
		return (ft_putnbr_base_signed(*(uint32_t *)arg.value, UHEX_CHARSET));
	else if (arg.type == PTR)
		return (ft_putstr("0x") + ft_putnbr_base(*(uint64_t *)arg.value,
				LHEX_CHARSET));
	return (-1);
}
