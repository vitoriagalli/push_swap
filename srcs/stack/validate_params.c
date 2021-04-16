/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 23:39:48 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/16 03:45:10 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

static bool	is_numerical_param(char **argv)
{
	int	param;
	int	count_char;

	param = 0;
	while (argv[param])
	{
		count_char = 0;
		if (argv[param][count_char] == '-')
			count_char++;
		if (!ft_isdigit(argv[param][count_char]))
			return (false);
		while (argv[param][count_char])
		{
			if (!ft_isdigit(argv[param][count_char]))
				return (false);
			count_char++;
		}
		param++;
	}
	return (true);
}

static bool	check_range(char *str, char *limit)
{
	int	i;

	if (ft_strlen(str) > ft_strlen(limit))
		return (false);
	if (ft_strlen(str) < ft_strlen(limit))
		return (true);
	i = 0;
	while (str[i] == limit[i])
	{
		if (!str[i])
			return (true);
		i++;
	}
	if (str[i] > limit[i])
		return (false);
	return (true);
}

static bool	is_integer_param(char **argv)
{
	int		param;
	char	*limit;

	param = 0;
	while (argv[param])
	{
		if (argv[param][0] == '-')
			limit = "-2147483648";
		else
			limit = "2147483647";
		if (!check_range(argv[param], limit))
			return (false);
		param++;
	}
	return (true);
}

static bool	is_dup_param(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (!ft_strcmp(argv[i], argv[j]))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	validate_params(char **argv)
{
	if (!is_numerical_param(argv))
		return (false);
	if (!is_integer_param(argv))
		return (false);
	if (is_dup_param(argv))
		return (false);
	return (true);
}
