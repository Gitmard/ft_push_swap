/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:16:39 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/14 14:58:41 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bench_defines.h"

void	print_disorder(float disorder)
{
	int		int_disorder;
	int		power;
	char	c;

	power = 0;
	ft_putstr_stderr("[bench] disorder:  ");
	int_disorder = (int)(disorder * 10000 + 0.5);
	if (int_disorder == 0)
	{
		ft_putstr_stderr("0,00%\n");
		return ;
	}
	power = get_power(int_disorder);
	while (power > 0)
	{
		if (power == 10)
			ft_putstr_stderr(",");
		c = '0' + int_disorder / power;
		write(2, &c, 1);
		int_disorder %= power;
		power /= 10;
	}
	ft_putstr_stderr("%\n");
}

void	print_strategy(t_stacks *stacks, float disorder)
{
	ft_putstr_stderr("[bench] strategy:  ");
	if (((stacks->flags ^ BENCH) & ADAPTIVE)
		|| (stacks->flags ^ BENCH) == 0)
	{
		ft_putstr_stderr("Adaptive / ");
		if (disorder < 0.2)
			ft_putstr_stderr("O(n²)\n");
		else if (disorder < 0.5)
			ft_putstr_stderr("O(n√n)\n");
		else
			ft_putstr_stderr("O(n log n)\n");
		return ;
	}
	if (stacks->flags & SIMPLE)
		ft_putstr_stderr("O(n²)\n");
	else if (stacks->flags & MEDIUM)
		ft_putstr_stderr("O(n√n)\n");
	else
		ft_putstr_stderr("O(n log n)\n");
}

void	print_op(t_op op)
{
	ft_putstrnbr_stderr("[bench] total_ops:  ", op.total);
	ft_putstrnbr_stderr("\n[bench] sa:  ", op.sa);
	ft_putstrnbr_stderr("  sb:  ", op.sb);
	ft_putstrnbr_stderr("  ss:  ", op.ss);
	ft_putstrnbr_stderr("  pa:  ", op.pa);
	ft_putstrnbr_stderr("  pb:  ", op.pb);
	ft_putstrnbr_stderr("\n[bench] ra:  ", op.ra);
	ft_putstrnbr_stderr("  rb:  ", op.rb);
	ft_putstrnbr_stderr("  rr:  ", op.rr);
	ft_putstrnbr_stderr("  rra:  ", op.rra);
	ft_putstrnbr_stderr("  rrb:  ", op.rrb);
	ft_putstrnbr_stderr("  rrr:  ", op.rrr);
	ft_putstr_stderr("\n");
}

void	bench(t_stacks *stacks, float disorder)
{
	print_disorder(disorder);
	print_strategy(stacks, disorder);
	print_op(stacks->op);
}
