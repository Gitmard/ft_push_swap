/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:51:49 by smenard           #+#    #+#             */
/*   Updated: 2026/01/12 10:28:56 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_LIB_H
# define PRINTF_LIB_H
# include "printf_defines.h"

/* parse.c */
void		ft_parse_arg(t_string str, va_list ap, size_t *ptr_i, t_arg *arg);

/* print.c */
ssize_t		ft_putstr(t_string str);

ssize_t		ft_putnbr_base_signed(int64_t num, t_string base);

ssize_t		ft_putnbr_base(uint64_t num, t_string base);

ssize_t		ft_print_arg(t_arg arg);

/* utils.c */
size_t		ft_strlen(t_string str);

size_t		ft_strlen_until(t_string str, char stop);

char		*ft_strchr(t_string str, char c);

t_string	ft_strdup(t_string str);

#endif
