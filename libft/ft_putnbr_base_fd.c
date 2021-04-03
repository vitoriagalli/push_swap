/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:48:19 by vscabell          #+#    #+#             */
/*   Updated: 2020/08/11 03:50:36 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	unsigned values
*/

void	ft_putnbr_base_fd(unsigned int n, char *base, int fd)
{
	size_t	size_base;

	size_base = ft_strlen(base);
	if (n / size_base > 0)
		ft_putnbr_base_fd(n / size_base, base, fd);
	ft_putchar_fd(base[n % size_base], fd);
}
