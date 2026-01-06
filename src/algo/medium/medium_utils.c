/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:15:25 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/06 11:40:44 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int x)
{
	int	min;
	int	max;
	int	mid;

	mid = 0;
	max = x + 1 / 2;
	while (max >= min)
	{
		mid = min + (max - min) / 2;
		if (mid * mid > x)
			max = mid - 1;
		else if (mid * mid < x)
			min = mid + 1;
		else
			return (mid);
	}
	if (x - (max * max) > (min * min) - x)
		return (min);
	return (max);
}
