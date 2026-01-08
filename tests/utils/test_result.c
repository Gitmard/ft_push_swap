/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_result.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:44:56 by smenard           #+#    #+#             */
/*   Updated: 2026/01/07 15:45:44 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_tests_instructions.h"

test_result_t	build_result(char *got, bool success)
{
	test_result_t	result;

	result.got = got;
	result.success = success;
	return (result);
}
