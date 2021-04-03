/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 04:05:38 by vscabell          #+#    #+#             */
/*   Updated: 2020/08/12 03:03:02 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putnbr_base_long_fd(unsigned long int n, char *base, int fd)
{
	size_t	size_base;

	size_base = ft_strlen(base);
	if (n / size_base > 0)
		ft_putnbr_base_long_fd(n / size_base, base, fd);
	ft_putchar_fd(base[n % size_base], fd);
}

static int	ft_number_len(unsigned long int number, int base_size)
{
	size_t	len;

	len = 1;
	while (number / base_size > 0)
	{
		len++;
		number /= base_size;
	}
	return (len);
}

void		print_pointer(va_list ap, t_flags *flags)
{
	unsigned long int	addr;
	int					len;
	int					space;
	int					precision;

	addr = va_arg(ap, unsigned long int);
	len = ft_number_len(addr, 16);
	precision = flags->precision > len ? flags->precision - len : 0;
	len = !addr && flags->dot && !flags->precision ? 2 : len + 2;
	space = flags->width > len ? flags->width - len : 0;
	flags->ret += len + space + precision;
	if (!flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	write(1, "0x", 2);
	while (precision-- > 0)
		ft_putchar_fd('0', 1);
	if (len > 2)
		ft_putnbr_base_long_fd(addr, HEX_LOWER, 1);
	if (flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}
