/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 23:59:17 by dwuthric          #+#    #+#             */
/*   Updated: 2022/07/15 09:29:32 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	conversion cspdiuxX%
	c - character
	s - string of characters
	p - pointer adress
	d - signed decimal integer
	i - signed decimal integer
	u - unsigned decimal integer
	x - unsigned hex integer, lowercase
	X - unsigned hex integer, uppercase
	% - print %

	flags -0.*
	- - Left-justify within the given field width; Right justification is the default
	0 - Left-pads the number with zeroes (0) instead of spaces

	length l ll h hh

	%[flags][width][.precision][length]spec
*/

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		done;

	va_start(args, fmt);
	done = ft_vfprintf(STDOUT_FILENO, fmt, args);
	va_end(args);
	return (done);
}

int		ft_vprintf(const char *fmt, va_list args)
{
	return (ft_vfprintf(STDOUT_FILENO, fmt, args));
}

int	ft_vfprintf(int fd, const char *fmt, va_list args)
{
	t_info	info;

	_init_info(&info, fd);
	while (*fmt)
	{
		_reset_info(&info);
		if (*fmt != '%')
			_putc(*fmt, &info);
		else
			info.state = STATE_LENGTH;
		_state_length(&fmt, &info);
		_state_spec(&fmt, args, &info);
		fmt++;
	}
	return (info.size);
}

void	_state_length(const char **fmt, t_info *info)
{
	if (info->state == STATE_LENGTH)
	{
		fmt[0]++;
		if (**fmt == 'h')
		{
			info->length = LENGTH_SHORT;
			fmt[0]++;
			if (**fmt == 'h')
				info->length = LENGHT_SHORTSHORT;
		}
		else if (**fmt == 'l')
		{
			info->length = LENGTH_LONG;
			fmt[0]++;
			if (**fmt == 'l')
				info->length = LENGTH_LONGLONG;
		}
		if (info->length == LENGTH_LONGLONG || info->length == LENGHT_SHORTSHORT)
			fmt[0]++;
		info->state = STATE_SPEC;
		fmt[0]--;
	}
}

void	_state_spec(const char **fmt, va_list args, t_info *info)
{
	if (info->state == STATE_SPEC)
	{
		fmt[0]++;
		if (**fmt == 'c')
			_putc(va_arg(args, int), info);
		else if (**fmt == 's')
			_puts(va_arg(args, char*), info);
		else if(**fmt == '%')
			_putc('%', info);
		else if(**fmt == 'd' || **fmt == 'i')
			_putnum(args, info, true, 10);
		else if(**fmt == 'u')
			_putnum(args, info, false, 10);
		else if(**fmt == 'x')
			_putnum(args, info, false, 16);
		else if(**fmt == 'X')
		{
			info->upper = true;
			_putnum(args, info, false, 16);
		}
		else if (**fmt == 'p')
		{
			_puts("0x", info);
			_putnum(args, info, false, 16);
		}
		else
			fmt--;
		fmt++;
	}
}

void	_init_info(t_info *info, int fd)
{
	info->fd = fd;
	info->state = STATE_DEFAULT;
	info->length = LENGTH_DEFAULT;
	info->size = 0;
	info->upper = false;
}

void	_reset_info(t_info *info)
{
	info->state = STATE_DEFAULT;
	info->length = LENGTH_DEFAULT;
	info->upper = false;
}

void	_putc(char c, t_info *info)
{
	info->size++;
	ft_putchar_fd(c, info->fd);
}

void	_puts(char *str, t_info *info)
{
	info->size += ft_strlen(str);
	ft_putstr_fd(str, info->fd);
}
