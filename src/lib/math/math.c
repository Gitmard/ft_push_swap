/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:36:00 by smenard           #+#    #+#             */
/*   Updated: 2026/01/13 11:02:23 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_sqrt(int n)
{
	int	min;
	int	max;
	int	mid;

	min = 0;
	max = n + 1 / 2;
	while (max >= min)
	{
		mid = min + (max - min) / 2;
		if (mid * mid > n)
			max = mid - 1;
		else if (mid * mid < n)
			min = mid + 1;
		else
			return (mid);
	}
	if (n - (max * max) > (min * min) - n)
		return (min);
	return (max);
}
