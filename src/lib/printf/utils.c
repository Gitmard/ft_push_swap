/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:06:22 by smenard           #+#    #+#             */
/*   Updated: 2026/01/12 10:28:53 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_lib.h"

size_t	ft_strlen(t_string str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlen_until(t_string str, char stop)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] && str[len] != stop)
		len++;
	return (len);
}

char	*ft_strchr(t_string str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

t_string	ft_strdup(t_string str)
{
	size_t		len;
	t_string	dup;
	size_t		i;

	len = ft_strlen(str);
	i = 0;
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
