/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 23:39:48 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/10 17:12:15 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static bool	is_numerical_param(int argc, char **argv)
{
	int	param;
	int	count_char;

	param = 1;
	while (param < argc)
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

static bool	is_integer_param(int argc, char **argv)
{
	int		param;
	char	*limit;

	param = 1;
	while (param < argc)
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

static bool	is_dup_param(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (!ft_strcmp(argv[i], argv[j]))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	validate_params(int argc, char **argv)
{
	if (!is_numerical_param(argc, argv))
		return (false);
	if (!is_integer_param(argc, argv))
		return (false);
	if (is_dup_param(argc, argv))
		return (false);
	return (true);
}
