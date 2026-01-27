/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:44:51 by smenard           #+#    #+#             */
/*   Updated: 2026/01/27 13:54:18 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_includes.h"

int	binary_search(int value, int *tab, int tab_len)
{
	int	left;
	int	right;
	int	middle;

	left = 0;
	right = tab_len - 1;
	while (left <= right)
	{
		middle = left + (int)((right - left) / 2);
		if (tab[middle] < value)
			left++;
		else if (tab[middle] > value)
			right--;
		else
			return (middle);
	}
	return (-1);
}
