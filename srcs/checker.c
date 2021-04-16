/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:17:41 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/16 03:42:33 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_and_execute_commands(t_stacks *stacks)
{
	char	*cmd;
	int		ret;

	print_stacks(*stacks);
	while (true)
	{
		ret = get_next_line(STDIN_FILENO, &cmd);
		if (ret <= 0)
			break ;
		operations(cmd, stacks);
		free(cmd);
		print_stacks(*stacks);
	}
	free(cmd);
}

void	check_if_is_sorted(t_stacks *stacks)
{
	bool	sorted;

	sorted = is_sorted(stacks);
	if (sorted)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

char	**unify_args(int argc, char **argv)
{
	char	**argv_split;
	char	*string;
	char	*tmp;
	int		i;

	i = 1;
	string = ft_strdup("");
	while (i < argc)
	{
		tmp = ft_strjoin(argv[i], " ");
		string = ft_strjoin_and_free(string, tmp);
		i++;
	}
	argv_split = ft_split(string, ' ');
	free (string);
	return (argv_split);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		**argv_split;

	argv_split = unify_args(argc, argv);
	validate_args(argc, argv_split);
	build_stacks(argv_split, &stacks);
	ft_array_clear(argv_split);
	read_and_execute_commands(&stacks);
	check_if_is_sorted(&stacks);
	clear_stacks(&stacks);
	return (EXIT_SUCCESS);
}
