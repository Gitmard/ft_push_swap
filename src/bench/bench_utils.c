/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:57:42 by vquetier          #+#    #+#             */
/*   Updated: 2026/02/02 15:31:20 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench_includes.h"

int	get_power(int n)
{
	int	power;

	power = 1;
	while (n > 9)
	{
		power *= 10;
		n /= 10;
	}
	return (power);
}

void	ft_putstr_stderr(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, str, len);
}

void	ft_putstrnbr_stderr(char *str, int n)
{
	int		power;
	char	c;

	ft_putstr_stderr(str);
	power = get_power(n);
	while (power > 0)
	{
		c = '0' + n / power;
		write(2, &c, 1);
		n %= power;
		power /= 10;
	}
}
