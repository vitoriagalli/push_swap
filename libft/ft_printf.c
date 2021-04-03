/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 04:18:41 by vscabell          #+#    #+#             */
/*   Updated: 2020/08/12 02:40:14 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	init_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->negative = 0;
	flags->dot = 0;
}

static void	handle_conversions(const char *format, va_list ap, t_flags *flags)
{
	store_flags(format, ap, flags);
	if (format[flags->index] == 'c')
		print_char(ap, flags);
	else if (format[flags->index] == 's')
		print_string(ap, flags);
	else if (format[flags->index] == 'p')
		print_pointer(ap, flags);
	else if (format[flags->index] == 'd' || format[flags->index] == 'i' ||
	format[flags->index] == 'u' || format[flags->index] == 'x' ||
	format[flags->index] == 'X')
		print_diux(ap, format[flags->index], flags);
	else if (format[flags->index] == '%')
		print_percent(flags);
	else
	{
		write(1, "%", 1);
		flags->index--;
		flags->ret++;
	}
	init_flags(flags);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flags	flags;

	flags.index = 0;
	flags.ret = 0;
	init_flags(&flags);
	va_start(ap, format);
	while (format[flags.index])
	{
		if (format[flags.index] == '%')
			handle_conversions(format, ap, &flags);
		else
		{
			ft_putchar_fd(format[flags.index], 1);
			flags.ret++;
		}
		flags.index++;
	}
	va_end(ap);
	return (flags.ret);
}
