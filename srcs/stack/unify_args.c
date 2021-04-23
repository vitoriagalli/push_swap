/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unify_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 03:57:17 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/22 00:53:25 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void	exit_program(t_stacks *stacks)
{
	clear_stacks(stacks);
	exit(EXIT_FAILURE);
}

void	validate_args(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_array_clear((void **)argv);
		exit(EXIT_SUCCESS);
	}
	if (!validate_params(argv))
	{
		ft_array_clear((void **)argv);
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

char	**unify_args(int argc, char **argv)
{
	char	**argv_split;
	char	*string;
	char	*tmp;
	int		i;

	string = ft_strdup("");
	if (!string)
		exit(EXIT_FAILURE);
	i = 1;
	while (i < argc)
	{
		tmp = ft_strjoin(argv[i], " ");
		if (!tmp)
			exit(EXIT_FAILURE);
		string = ft_strjoin_and_free(string, tmp);
		if (!string)
			exit(EXIT_FAILURE);
		i++;
	}
	argv_split = ft_split(string, ' ');
	free (string);
	if (!argv_split)
		exit(EXIT_FAILURE);
	return (argv_split);
}
