/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:08:15 by dwuthric          #+#    #+#             */
/*   Updated: 2022/10/30 22:27:14 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*parse_flags(const char *fmt, t_info *info)
{
	(void)info;
	return (fmt);
}

const char	*parse_width(const char *fmt, t_info *info)
{
	(void)info;
	return (fmt);
}

const char	*parse_precision(const char *fmt, t_info *info)
{
	(void)info;
	return (fmt);
}

const char	*parse_length(const char *fmt, t_info *info)
{
	(void)info;
	return (fmt);
}

const char	*parse_specifier(const char *fmt, t_info *info, va_list args)
{
	if (*fmt == 'c')
		_putc(info, va_arg(args, int));
	else if (*fmt == 's')
		_puts(info, va_arg(args, char *));
	else if (*fmt == 'p')
		_putptr(info, args);
	else if (*fmt == 'd' || *fmt == 'i')
		_putnum(info, args, true, 10);
	else if (*fmt == 'u')
		_putnum(info, args, false, 10);
	else if (*fmt == 'x')
		_putnum(info, args, false, 16);
	else if (*fmt == 'X')
		_putbigx(info, args);
	else if (*fmt == '%')
		_putc(info, '%');
	else
		return (fmt);
	return (fmt + 1);
}
