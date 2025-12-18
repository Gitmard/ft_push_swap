/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:41:35 by smenard           #+#    #+#             */
/*   Updated: 2025/12/18 13:42:06 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include "string_includes.h"

int	ft_strcmp(char *s1, char *s2);

int	ft_strncmp(char *s1, char *s2, size_t n);

#endif