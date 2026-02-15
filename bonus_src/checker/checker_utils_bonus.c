/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:13:31 by vquetier          #+#    #+#             */
/*   Updated: 2026/02/15 13:22:20 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	flush_stdout(void)
{
	char	buffer[256];
	int		rd_char;

	rd_char = read(0, buffer, 256);
	while (rd_char > 0)
		rd_char = read(0, buffer, 256);
}

void	(**get_functions(void))(t_stacks *stacks)
{
	void	(**f)(t_stacks *stacks);

	f = malloc(sizeof(*f) * 11);
	if (!f)
		return (NULL);
	f[0] = &pa;
	f[1] = &pb;
	f[2] = &ra;
	f[3] = &rb;
	f[4] = &rra;
	f[5] = &rrb;
	f[6] = &rr;
	f[7] = &rrr;
	f[8] = &sa;
	f[9] = &sb;
	f[10] = &ss;
	return (f);
}

void	raise_error_checker(void)
{
	write(2, "Error\n", 6);
}

void	clean_exit(t_stacks *stacks, uint32_t flags, int value)
{
	uint32_t	free_flag;

	free_flag = flags & FREE_STACKS_ALL;
	free_stacks(stacks, free_flag);
	if (flags & RAISE_ERROR)
		raise_error_checker();
	if (!(flags & DONT_FLUSH_STDOUT))
		flush_stdout();
	exit(value);
}
