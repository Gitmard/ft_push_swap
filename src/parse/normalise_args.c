/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquetier <vquetier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:18:20 by vquetier          #+#    #+#             */
/*   Updated: 2026/01/09 11:18:46 by vquetier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parse_defines.h"

int	count_words(char *arg)
{
	bool	flag;
	int		count;
	int		i;

	flag = true;
	count = 0;
	i = 0;
	while (arg[i])
	{
		if (arg[i] == ' ')
			flag = true;
		else if (flag)
		{
			count++;
			flag = false;
		}
		i++;
	}
	return (count);
}

int	count_full_words(int ac, char **av)
{
	int	words_count;
	int	i;

	words_count = 1;
	i = 1;
	while (i < ac)
	{
		words_count += count_words(av[i]);
		i++;
	}
	return (words_count);
}

char	*create_word(char *str)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (str[len] && str[len] != ' ')
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

int	create_split(char **split, int *j, char *arg, int *n_count)
{
	bool	flag;
	int		i;

	flag = true;
	i = 0;
	while (arg[i])
	{
		if (arg[i] == ' ')
			flag = true;
		else if (flag)
		{
			if (arg[i] >= '0' && arg[i] <= '9')
				(*n_count)++;
			split[*j] = create_word(&arg[i]);
			if (!split[*j])
				return (ERROR);
			(*j)++;
			flag = false;
		}
		i++;
	}
	return (SUCCESS);
}

int	normalise_args(int *ac, char ***av, int *n_count)
{
	int		words_count;
	char	**split;
	int		i;
	int		j;

	words_count = count_full_words(*ac, *av);
	split = malloc(sizeof(char *) * words_count);
	if (!split)
		return (1);
	split[words_count - 1] = NULL;
	i = 1;
	j = 0;
	while (i < *ac)
	{
		if (create_split(split, &j, (*av)[i], n_count))
			return (free_split(split));
		i++;
	}
	*av = split;
	*ac = words_count - 1;
	return (SUCCESS);
}
