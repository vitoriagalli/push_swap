/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:59:46 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/10 17:08:03 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_and_execute_commands(t_stacks *stacks)
{
	char *cmd;

	print_stacks(*stacks);
	while (true)
	{
		ft_printf("cmd: ");
		get_next_line(STDIN_FILENO, &cmd);
		operations(cmd, stacks);
		print_stacks(*stacks);
	}
}
