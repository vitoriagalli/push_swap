/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .print_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 04:18:04 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/04 03:25:25 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

static int	ft_number_len(unsigned int number, int base_size)
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

void	get_len(t_flags *flags, int *len, unsigned int num)
{
	if (flags->negative)
		(*len)++;
	if (flags->dot && !flags->precision && !num)
		(*len) = 0;
}

int	get_zeros(t_flags *flags, int len)
{
	int	zero;

	zero = 0;
	if (flags->precision > len)
		zero = flags->precision - len;
	else if (flags->width > len && flags->zero)
		zero = flags->width - len;
	return (zero);
}

static void	paddle_flags(t_flags *flags, unsigned int num, int len, char *base)
{
	int	zero;
	int	space;

	space = 0;
	get_len(flags, &len, num);
	zero = get_zeros(flags, len);
	if (zero > 0)
		len += zero;
	if (flags->width > len && !flags->zero)
		space = flags->width - len;
	flags->ret += len + space;
	if (!flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	if (flags->negative)
		ft_putchar_fd('-', 1);
	while (zero-- > 0)
		ft_putchar_fd('0', 1);
	if (len)
		ft_putnbr_base_fd(num, base, 1);
	if (flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}

void	print_diux(va_list ap, char c, t_flags *flags)
{
	int				num;
	unsigned int	u_num;

	if (c == 'i' || c == 'd')
	{
		num = va_arg(ap, int);
		if (num < 0)
		{
			flags->negative = 1;
			num *= -1;
			if (flags->precision > 0)
				flags->precision += 1;
		}
		paddle_flags(flags, num, ft_number_len(num, 10), DEC);
	}
	else if (c == 'u' || c == 'x' || c == 'X')
	{
		u_num = va_arg(ap, unsigned int);
		if (c == 'u')
			paddle_flags(flags, u_num, ft_number_len(u_num, 10), DEC);
		else if (c == 'x')
			paddle_flags(flags, u_num, ft_number_len(u_num, 16), HEX_LOWER);
		else
			paddle_flags(flags, u_num, ft_number_len(u_num, 16), HEX_UPPER);
	}
}
