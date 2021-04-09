/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:17:41 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/09 03:53:56 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

bool	is_numerical_param(int argc, char **argv)
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

bool	check_range(char *str, char *limit)
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

bool	is_integer_param(int argc, char **argv)
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

bool	check_param(int argc, char **argv)
{
	if (argc == 1)	// not display anithing and give the prompt back
		return (false);
	if (!is_numerical_param(argc, argv))
		return (false);
	if (!is_integer_param(argc, argv))
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	if (!check_param(argc, argv))
	{
		ft_printf("Error\n");
		return (1);
	}
	ft_printf("param ok");
	return (0);
}
