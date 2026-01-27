/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:37:23 by smenard           #+#    #+#             */
/*   Updated: 2026/01/27 15:27:21 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo_includes.h"
#include "algo.h"

int	adaptive(t_stacks *stacks, float disorder)
{
	int			res;

	res = 0;
	if (disorder <= 0.2)
		simple(stacks);
	else if (disorder <= 0.5)
		res = medium(stacks);
	else
	{
		ft_printf("ERROR: complex not implemented.\n");
		res = -1;
	}
	return (res);
}
